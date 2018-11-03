#include <string.h>

#include <xcb/xcb.h>
#include <xcb/xcb_atom.h>
#include <X11/Xlib-xcb.h>

#include "quadint.h"

#define QUAD_GET_XCB_CONNECTION(ptr) \
	((xcb_connection_t *)ptr->display.data)

void _QNativeDisplayInit(const char *display_name)
{
	Display *display = XOpenDisplay(display_name);
	if (display == NULL) {
		_QFatal("failed to open X display.");
	}

	xcb_connection_t *connection  = XGetXCBConnection(display);
	if (connection == NULL) {
		_QFatal("failed to open XCB connection to X server.");
	}

	if (xcb_connection_has_error(connection)) {
		_QFatal("error ocurred in connecting to X server.");
	}

	/* save native display */
	_Q_ptr->display.native = display;

	/* save xcb connection */
	_Q_ptr->display.data = connection;
}

void _QNativeDisplayFinalize(void)
{
	
}

void _QNativeWindowInit(Quad_Window *win, const char *title,
	int x, int y, int w, int h)
{
	xcb_connection_t      *connection = QUAD_GET_XCB_CONNECTION(_Q_ptr);
	const xcb_setup_t     *setup      = xcb_get_setup(connection);
	xcb_screen_iterator_t iter        = xcb_setup_roots_iterator(setup);
	xcb_screen_t          *screen     = iter.data;

	if (screen == NULL) {
		_QFatal("failed to get xcb screen.");
	}

	/* create the window */

	xcb_window_t window = xcb_generate_id(connection);
	if (window == 0) {
		_QFatal("failed to generate a X window id.");
	}
	
	xcb_void_cookie_t create_ok = xcb_create_window(connection,
		XCB_COPY_FROM_PARENT, window, screen->root,
		x, y, w, h, 0, XCB_WINDOW_CLASS_INPUT_OUTPUT,
		screen->root_visual, 0, NULL);

	if (xcb_request_check(connection, create_ok)) {
		_QFatal("failed to create X window.");
	}
	
	/* set title of the window */

	xcb_change_property(connection, XCB_PROP_MODE_REPLACE,
		window, XCB_ATOM_WM_NAME, XCB_ATOM_STRING,
		8, strlen(title), title);
	
	/* set title of the window icon*/

	xcb_change_property(connection, XCB_PROP_MODE_REPLACE,
		window, XCB_ATOM_WM_ICON_NAME, XCB_ATOM_STRING,
		8, strlen(title), title);

	/* map the window */

	xcb_void_cookie_t map_ok = xcb_map_window(connection, window);

	if (xcb_request_check(connection, map_ok)) {
		_QFatal("failed to map X window.");
	}

	/* flush */
	xcb_flush(connection);
	
	/* Window type from X and window_t from xcb are both 32 bit integer */
	/* save xcb window */
	win->native.graphics.window = window;
	win->native.width  = w;
	win->native.height = h;
}

void _QNativeWindowFinalize(Quad_Window *win)
{
}
