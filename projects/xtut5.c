/* first include the standard headers that we're likely to need */
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xresource.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GC setup(Display * dpy, int argc, char ** argv, int *width_r, int *height_r,
		XFontStruct **font_r){
	int width, height;
	int screen_num;
	unsigned long background, border;
	Window win;
	GC pen;
	XGCValues values;

	char * fontname;
	XFontStruct *font;
	Colormap cmap;
	XColor xc, xc2;

	screen_num = DefaultScreen(dpy);

	cmap = DefaultColormap(dpy, screen_num);

	XAllocNamedColor(dpy, cmap, "DarkGreen", &xc, &xc2);
	background = xc.pixel;
	XAllocNamedColor(dpy, cmap, "LightGreen", &xc, &xc2);
	border = xc.pixel;
	XAllocNamedColor(dpy, cmap, "Red", &xc, &xc2);
	values.foreground = xc.pixel;

	fontname = "-*-helvetica-*-10-*";
	font = XLoadQueryFont(dpy, fontname);
	if (!font) {
		fprintf(stderr, "unable to load preferred font: %s using fixed\n", fontname);
		font = XLoadQueryFont(dpy, "fixed");
	}

	width = 400;
	height = 400;

	win = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), /* display, parent */
		0,0, /* x, y: the window manager will place the window elsewhere */
		width, height, /* width, height */
		2, border, /* border width & colour, unless you have a window manager */
		background); /* background colour */

	/* create the pen to draw lines with */
	values.line_width = 1;
	values.line_style = LineSolid;
	values.font = font->fid;
	pen = XCreateGC(dpy, win, GCForeground|GCLineWidth|GCLineStyle|GCFont,&values);

	/* tell the display server what kind of events we would like to see */
	XSelectInput(dpy, win, ButtonPressMask|StructureNotifyMask|ExposureMask);

	/* okay, put the window on the screen, please */
	XMapWindow(dpy, win);

	*width_r = width; *height_r = height;
	*font_r = font;

	return pen;
}

int main_loop(Display *dpy, XFontStruct *font, GC pen, int width, int height,
		 char *text){
	int text_width;
	int textx, texty;
	XEvent ev;

	text_width = XTextWidth(font, text, strlen(text));

	/* as each event that we asked about occurs, we respond. */
	while(1){
		XNextEvent(dpy, &ev);
		switch(ev.type){
		case Expose:
			XDrawLine(dpy, ev.xany.window, pen, 0, 0, width/2-text_width/2, height/2);
			XDrawLine(dpy, ev.xany.window, pen, width, 0, width/2+text_width/2, height/2);
			XDrawLine(dpy, ev.xany.window, pen, 0, height, width/2-text_width/2, height/2);
			XDrawLine(dpy, ev.xany.window, pen, width, height, width/2+text_width/2, height/2);
   			textx = (width - text_width)/2;
   			texty = (height + font->ascent)/2;
   			XDrawString(dpy, ev.xany.window, pen, textx, texty, text, strlen(text));
			break;
		case ConfigureNotify:
			if (width != ev.xconfigure.width
					|| height != ev.xconfigure.height) {
				width = ev.xconfigure.width;
				height = ev.xconfigure.height;
				XClearWindow(dpy, ev.xany.window);
				printf("Size changed to: %d by %d\n", width, height);
			}
			break;
		case ButtonPress:
			XCloseDisplay(dpy);
			return 0;
		}
	}
}

int main(int argc, char ** argv){
	int width, height;
	Display *dpy;
	GC pen;
	XFontStruct *font;

	/* First connect to the display server */
	dpy = XOpenDisplay(NULL);
	if (!dpy) {fprintf(stderr, "unable to connect to display\n");return 7;}
	pen = setup(dpy, argc, argv, &width, &height, &font);
	return main_loop(dpy, font, pen, width, height, "Hi!");
}