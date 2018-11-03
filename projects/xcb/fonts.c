#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <xcb/xcb.h>

#define WIDTH  300
#define HEIGHT 100

static xcb_gc_t gc_get_font(xcb_connection_t *conn, xcb_screen_t *screen,
	xcb_window_t window, const char *font_name)
{
	xcb_void_cookie_t cookie_gc;
	xcb_void_cookie_t cookie_font;

	xcb_generic_error_t *error;
	xcb_font_t          font;
	xcb_gcontext_t      gc;

	uint32_t  mask;
	uint32_t  value_list[3];

	font        = xcb_generate_id(conn);
	cookie_font = xcb_open_font_checked(conn, font, strlen(font_name),
		font_name);

	error = xcb_request_check(conn, cookie_font);
	if (error) {
		fprintf(stderr, "ERROR: can't open font: %d\n",
			error->error_code);
		xcb_disconnect(conn);
		exit(EXIT_FAILURE);
	}
	
	gc   = xcb_generate_id(conn);
	mask = XCB_GC_FOREGROUND | XCB_GC_BACKGROUND | XCB_GC_FONT;
	
	value_list[0] = screen->black_pixel;
	value_list[1] = screen->white_pixel;
	value_list[2] = font;
	cookie_gc = xcb_create_gc_checked(conn, gc, window, mask, value_list);
	
	error = xcb_request_check(conn, cookie_gc);
	if (error) {
		fprintf(stderr, "ERROR: can't create gc: %d\n",
			error->error_code);
		xcb_disconnect(conn);
		exit(EXIT_FAILURE);
	}

	cookie_font = xcb_close_font_checked(conn, font);
	if (error) {
		fprintf(stderr, "ERROR: can't close font: %d\n",
			error->error_code);
		xcb_disconnect(conn);
		exit(EXIT_FAILURE);
	}

	return gc;	
}

static void text_draw(xcb_connection_t *conn, xcb_screen_t *screen,
	xcb_window_t window, int16_t x1, int16_t y1, const char *label)
{
	xcb_void_cookie_t cookie_gc;
	xcb_void_cookie_t cookie_text;

	xcb_generic_error_t *error;
	xcb_gcontext_t      gc;
	uint8_t             lenght;

	lenght = strlen(label);
	gc     = gc_get_font(conn, screen, window, "7x13");
	
	cookie_text = xcb_image_text_8_checked(conn, lenght, window,
		gc, x1, y1, label);

	error = xcb_request_check(conn, cookie_text);
	if (error) {
		fprintf(stderr, "ERROR: can't paste text: %d\n",
			error->error_code);
		xcb_disconnect(conn);
		exit(EXIT_FAILURE);
	}

	cookie_gc = xcb_free_gc(conn, gc);
	
	error = xcb_request_check(conn, cookie_gc);
	if (error) {
		fprintf(stderr, "ERROR: can't free gc: %d\n",
			error->error_code);
		xcb_disconnect(conn);
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{
	xcb_screen_iterator_t screen_iter;
	xcb_connection_t      *conn;
	xcb_screen_t          *screen;
	const xcb_setup_t     *setup;
	
	xcb_generic_event_t   *event;
	xcb_generic_error_t   *error;

	xcb_void_cookie_t     cookie_window;
	xcb_void_cookie_t     cookie_map;
	xcb_window_t          window;
	uint32_t              mask;
	uint32_t              values[2];
	int                   screen_num;

	conn = xcb_connect(NULL, &screen_num);
	if (!conn) {
		fprintf(stderr, "can't connect to the X server\n");
		exit(EXIT_FAILURE);
	}

	screen = NULL;
	setup  = xcb_get_setup(conn);

	screen_iter = xcb_setup_roots_iterator(setup);
	while (screen_iter.rem != 0) {
		if ((screen_num--) == 0) {
			screen = screen_iter.data;
			break;
		}

		xcb_screen_next(&screen_iter);
	}

	if (!screen) {
		fprintf(stderr, "can't get the current screen\n");
		xcb_disconnect(conn);	
		exit(EXIT_FAILURE);
	}

	window    = xcb_generate_id(conn);
	mask      = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
	values[0] = screen->white_pixel;
	values[1] = XCB_EVENT_MASK_KEY_RELEASE | XCB_EVENT_MASK_BUTTON_PRESS
		| XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_POINTER_MOTION;
	
	cookie_window = xcb_create_window_checked(conn, screen->root_depth,
		window, screen->root, 20, 200, WIDTH, HEIGHT, 0,
		XCB_WINDOW_CLASS_INPUT_OUTPUT, screen->root_visual,
		mask, values);

	cookie_map = xcb_map_window_checked(conn, window);

	error = xcb_request_check(conn, cookie_window);
	if (error) {
		fprintf(stderr, "can't create window: %d\n",
			error->error_code);
		xcb_disconnect(conn);	
		exit(EXIT_FAILURE);
	}

	error = xcb_request_check(conn, cookie_map);
	if (error) {
		fprintf(stderr, "can't map window: %d\n",
			error->error_code);
		xcb_disconnect(conn);	
		exit(EXIT_FAILURE);
	}

	xcb_flush(conn);
	static unsigned int quit;

	while (!quit) {
		static int i;
		event = xcb_poll_for_event(conn);
		if (event) {
			switch (event->response_type & ~0x80) {
			case XCB_EXPOSE: {
				char *text;
				text = "Press ESC to exit...";
				text_draw(conn, screen, window,
					10, HEIGHT -10, text);
				break;
			}

			case XCB_KEY_RELEASE: {
				xcb_key_release_event_t *ev;
				ev   = (xcb_key_release_event_t *)event;
				quit = (ev->detail == 9);
				break;
			}

			default: break;
			}

			free(event);
		}
		usleep(50 * 1000);
	}

	xcb_disconnect(conn);
	return 0;
		
}
