#include <unistd.h>
#include <xcb/xcb.h>

int main()
{
	xcb_connection_t *conn;
	xcb_screen_t     *screen;
	xcb_window_t     win;

	/*Open the connection to the X server*/
	conn = xcb_connect(NULL, NULL);
	
	/*Get the first screen*/
	screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;

	/*Ask for our window's id*/
	win = xcb_generate_id(conn);

	/*Create the window*/
	xcb_create_window(conn, XCB_COPY_FROM_PARENT, win, screen->root,
		0, 0, 150, 150, 10, XCB_WINDOW_CLASS_INPUT_OUTPUT,
		screen->root_visual, 0, NULL);

	/*Map the window on the screen*/
	xcb_map_window(conn, win);

	/*Make sure commands are sent before we pause, so window is shown*/
	xcb_flush(conn);

	pause();

	return 0;
}
