#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <xcb/xcb.h>
#include <xcb/xcb_atom.h>

int main()
{
	xcb_connection_t *conn;
	xcb_screen_t     *screen;
	xcb_window_t     win;

	char *title      = "Hello World!";
	char *title_icon = "Hello World! (iconified)";

	conn = xcb_connect(NULL, NULL);

	screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;
	
	win = xcb_generate_id(conn);
	xcb_create_window(conn, 0, win, screen->root, 0, 0, 250, 150, 10,
		XCB_WINDOW_CLASS_INPUT_OUTPUT, screen->root_visual, 0, NULL);

	xcb_change_property(conn, XCB_PROP_MODE_REPLACE, win,
		XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8,
		strlen(title), title);

	xcb_change_property(conn, XCB_PROP_MODE_REPLACE, win,
		XCB_ATOM_WM_ICON_NAME, XCB_ATOM_STRING, 8,
		strlen(title_icon), title_icon);

	xcb_map_window(conn, win);
	
	xcb_flush(conn);

	while (1) {usleep(50 * 1000);}
	return 0;
	
	
}
