#include <stdio.h>
#include <stdlib.h>

#include <X11/Xlib.h>
#include <X11/Xlib-xcb.h>
#include <xcb/xcb.h>

#include <GL/glx.h>
#include <GL/gl.h>

void draw()
{
	glClearColor(0.2, 0.4, 0.9, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

int main_loop(Display *dpy, xcb_connection_t *conn, xcb_window_t win,
	GLXDrawable drawable)
{
	int running = 1;
	while (running) {
		xcb_generic_event_t *event = xcb_wait_for_event(conn);
		if (!event) {
			fprintf(stderr, "i/o error in xcb_wait_for_event\n");
			return -1;
		}
	
		switch (event->response_type & ~0x80) {
		case XCB_KEY_PRESS:
			running = 0;
			break;
		case XCB_EXPOSE:
			draw();
			glXSwapBuffers(dpy, drawable);
			break;
		default: break;
		}

		free (event);	
	}

	return 0;
}

int setup_and_run(Display *dpy, xcb_connection_t *conn,
	int default_screen, xcb_screen_t *screen)
{
	int visualID       = 0;
	int num_fb_configs = 0;

	GLXFBConfig *fb_configs = 0;
	fb_configs = glXGetFBConfigs(dpy, default_screen, &num_fb_configs);

	if (!fb_configs || num_fb_configs == 0) {
		fprintf(stderr, "glXGetFBConfigs failed. :(\n");
		return -1;
	}

	GLXFBConfig fb_config = fb_configs[0];
	glXGetFBConfigAttrib(dpy, fb_config, GLX_VISUAL_ID, &visualID);
	
	GLXContext context;
	context = glXCreateNewContext(dpy, fb_config, GLX_RGBA_TYPE, 0, True);
	if (!context) {
		fprintf(stderr, "glXCreateNewContext failed :(\n");
	}
	
	xcb_colormap_t 	colormap = xcb_generate_id(conn);
	xcb_window_t    win      = xcb_generate_id(conn);

	xcb_create_colormap(conn, XCB_COLORMAP_ALLOC_NONE, colormap,
		screen->root, visualID);

	uint32_t eventmask   = XCB_EVENT_MASK_EXPOSURE
		| XCB_EVENT_MASK_KEY_PRESS;

	uint32_t valuelist[] = {eventmask, colormap, 0};
	uint32_t valuemask   = XCB_CW_EVENT_MASK | XCB_CW_COLORMAP;

	xcb_create_window(conn, XCB_COPY_FROM_PARENT, win, screen->root,
		0, 0, 150, 150, 0, XCB_WINDOW_CLASS_INPUT_OUTPUT,
		visualID, valuemask, valuelist);
	xcb_map_window(conn, win);

	GLXDrawable drawable = 0;
	GLXWindow glxwindow  =  glXCreateWindow(dpy, fb_config, win, 0);

	if (!win) {
		xcb_destroy_window(conn, win);
		glXDestroyContext(dpy, context);
		
		fprintf(stderr, "glXCreateWindow failed :(\n");
		return -1;
	}

	drawable = glxwindow;

	if (!glXMakeContextCurrent(dpy, drawable, drawable, context)) {
		xcb_destroy_window(conn, win);
		glXDestroyContext(dpy, context);
		
		fprintf(stderr, "glXMakeContext failed :(\n");
		return -1;
	}

	int retval = main_loop(dpy, conn, win, drawable);

	glXDestroyWindow(dpy, glxwindow);
	xcb_destroy_window(conn, win);
	glXDestroyContext(dpy, context);

	return retval;
}

int main(int argc, char **argv)
{
	Display *dpy;
	int default_screen;

	dpy = XOpenDisplay(0);
	if (!dpy) {
		fprintf(stderr, "Can't open display :(\n");
		exit(EXIT_FAILURE);
	}

	default_screen = DefaultScreen(dpy);

	xcb_connection_t *conn = XGetXCBConnection(dpy);
	if (!conn) {
		XCloseDisplay(dpy);
		fprintf(stderr, "Can't get xcb connection :(\n");
		exit(EXIT_FAILURE);
	}

	XSetEventQueueOwner(dpy, XCBOwnsEventQueue);

	xcb_screen_t *screen;
	screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;

	int retval = setup_and_run(dpy, conn, default_screen, screen);

	XCloseDisplay(dpy);
	return retval;

	
}
