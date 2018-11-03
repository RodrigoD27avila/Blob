#include <xcb/xcb.h>

int main()
{
	xcb_connection_t *c;
	c = xcb_connect(NULL, NULL);
	xcb_disconnect(c);
	return 0;
}
