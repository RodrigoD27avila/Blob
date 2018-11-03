#include <stdio.h>
#include <stdlib.h>

#include <xcb/xcb.h>

int main()
{
	xcb_connection_t    *conn;
	xcb_screen_t        *screen;
	xcb_generic_event_t *event;

	xcb_drawable_t win;
	xcb_gcontext_t foreground;
	uint32_t       mask;
	uint32_t       values[2];


	/*Geometric Objects*/

	xcb_point_t points[] = {
		{10, 10},
		{10, 20},
		{20, 10},
		{20, 20},
	};

	xcb_point_t polyline[] = {
		{50,  10},
		{5 ,  20},
		{25, -20},
		{10,  10},
	};

	xcb_segment_t segments[] = {
		{100, 10, 140, 30},
		{110, 25, 130, 60},
	};

	xcb_rectangle_t rectangles[] = {
		{10, 50, 40, 20},
		{80, 50, 10, 40},
	};

	xcb_arc_t arcs[] = {
		{10, 100, 60, 40, 0, 90  << 6},
		{90, 100, 55, 40, 0, 360 << 6},
	};

	/*Open the connecrion with X server*/
	conn = xcb_connect(NULL, NULL);

	/*Get the first screen*/
	screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;

	/*Create a black (foreground) graphic context*/
	win = screen->root;

	foreground = xcb_generate_id(conn);
	mask       = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
	values[0]  = screen->black_pixel;
	values[1]  = 0;
	xcb_create_gc(conn, foreground, win, mask, values);

	/*Ask for our window's id*/
	win = xcb_generate_id(conn);

	/*Create the window*/
	mask      = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
	values[0] = screen->white_pixel;
	values[1] = XCB_EVENT_MASK_EXPOSURE;
	xcb_create_window(conn, XCB_COPY_FROM_PARENT, win, screen->root,
		0, 0, 150, 150, 10, XCB_WINDOW_CLASS_INPUT_OUTPUT,
		screen->root_visual, mask, values);

	/*Map the window on the screen*/
	xcb_map_window(conn, win);

	/*We flush the request*/
	xcb_flush(conn);

	while ((event = xcb_wait_for_event(conn))) {
		switch (event->response_type & ~0x80) {
		case XCB_EXPOSE: {
			xcb_poly_point(conn, XCB_COORD_MODE_ORIGIN,
				win, foreground, 4, points);
			xcb_poly_line(conn, XCB_COORD_MODE_PREVIOUS,
				win, foreground, 4, polyline);

			xcb_poly_segment(conn, win, foreground,
				2, segments);
			xcb_poly_rectangle(conn, win, foreground,
				2, rectangles);

			xcb_poly_arc(conn, win, foreground, 2, arcs);
			
			xcb_flush(conn);
			break;
			
		}
		default: break;
		}
		
		free(event);
	}

	return 0;
}
