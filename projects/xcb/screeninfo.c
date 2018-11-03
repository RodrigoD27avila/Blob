#include <stdio.h>
#include <xcb/xcb.h>

int main()
{
	xcb_connection_t *conn;
	xcb_screen_t     *screen;
	int              screen_num;

	xcb_screen_iterator_t iter;

	/*Open the connection to the X server. Use the DISPLAY variable*/
	conn = xcb_connect(NULL, &screen_num);

	/*get the screen #screen_num*/
	iter = xcb_setup_roots_iterator(xcb_get_setup(conn));
	for (; iter.rem; screen_num--, xcb_screen_next(&iter)) {
		if (screen_num == 0) {
			screen = iter.data;
		}
	}

	printf("Informations of screen %u:\n", screen->root);
	printf("width..........: %d\n", screen->width_in_pixels);
	printf("height.........: %d\n", screen->height_in_pixels);
	printf("black pixel....: %u\n", screen->white_pixel);
	printf("white pixel....: %u\n", screen->black_pixel);

	return 0;
}

