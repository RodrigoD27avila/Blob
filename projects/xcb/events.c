#include <stdio.h>
#include <stdlib.h>

#include <xcb/xcb.h>

void print_modifiers(uint32_t mask)
{
	const char **mod, *mods[] = {
		"Shift", "Lock", "Ctrl", "Alt" ,
		"Mod2" , "Mod3", "Mod4", "Mod5",
		"Button1", "Button2", "Button3", "Button4", "Button5",
	};

	printf("Modifier mask: ");
	for (mod = mods; mask; mask >>= 1, mod++) {
		if (mask & 1) printf("%s\n", *mod);
	}
}

void on_xcb_expose(xcb_generic_event_t *event)
{
	xcb_expose_event_t *ev = (xcb_expose_event_t *)event;
	printf("Window %u exposed. Region to be redraw at location (%d, %d),"
		"with dimension (%d, %d)\n", ev->window, ev->x, ev->y,
		ev->width, ev->height); 
}

void on_xcb_button_press(xcb_generic_event_t *event)
{
	xcb_button_press_event_t *ev = (xcb_button_press_event_t *)event;
	print_modifiers(ev->state);

	switch (ev->detail) {
	case 4:
		printf("Wheel button up in window %u,"
			" at coordinades (%d, %d)\n", ev->event,
			ev->event_x, ev->event_y);
		break;
	case 5:
		printf("Wheel button down in window %u,"
			" at coordinades (%d, %d)\n", ev->event,
			ev->event_x, ev->event_y);
		break;
	default:
		printf("Button %d pressed in window %u,"
			" at coordinades (%d, %d)\n", ev->detail,
			ev->event, ev->event_x, ev->event_y);
		break;
		
	}
}

void on_xcb_button_release(xcb_generic_event_t *event)
{
	xcb_button_release_event_t *ev = (xcb_button_release_event_t *)event;
	print_modifiers(ev->state);
		
	printf("Button %d release in window %u, at coordinades (%d, %d)\n",
		 ev->detail, ev->event, ev->event_x, ev->event_y);
}

void on_xcb_motion_notify(xcb_generic_event_t *event)
{
	xcb_motion_notify_event_t *ev = (xcb_motion_notify_event_t *)event;
	printf("Mouse moved in window %u, at coordinades (%d, %d)\n",
		 ev->event, ev->event_x, ev->event_y);
}

void on_xcb_enter_notify(xcb_generic_event_t *event)
{
	xcb_enter_notify_event_t *ev = (xcb_enter_notify_event_t *)event;
	printf("Mouse entered window %u, at coordinades (%d, %d)\n",
		 ev->event, ev->event_x, ev->event_y);
}

void on_xcb_leave_notify(xcb_generic_event_t *event)
{
	xcb_leave_notify_event_t *ev = (xcb_leave_notify_event_t *)event;
	printf("Mouse left window %u, at coordinades (%d, %d)\n",
		 ev->event, ev->event_x, ev->event_y);
}

void on_xcb_key_press(xcb_generic_event_t *event)
{
	xcb_key_press_event_t *ev = (xcb_key_press_event_t *)event;
	printf("Key pressed in window %u\n", ev->event);
}

void on_xcb_key_release(xcb_generic_event_t *event)
{
	xcb_key_release_event_t *ev = (xcb_key_release_event_t *)event;
	printf("Key released in window %u\n", ev->event);
}

int main()
{
	xcb_connection_t    *conn;
	xcb_screen_t        *screen;
	xcb_generic_event_t *event;

	xcb_window_t win;
	uint32_t     mask;
	uint32_t     values[2];

	conn   = xcb_connect(NULL, NULL);
	screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;

	win  = xcb_generate_id(conn);
	mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
	
	values[0] = screen->white_pixel;
	values[1] = XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_BUTTON_PRESS
		| XCB_EVENT_MASK_BUTTON_RELEASE | XCB_EVENT_MASK_POINTER_MOTION
		| XCB_EVENT_MASK_ENTER_WINDOW   | XCB_EVENT_MASK_LEAVE_WINDOW
		| XCB_EVENT_MASK_KEY_PRESS      | XCB_EVENT_MASK_KEY_RELEASE;

	xcb_create_window(conn, 0, win, screen->root, 0, 0, 150, 150,
		10, XCB_WINDOW_CLASS_INPUT_OUTPUT, screen->root_visual,
		mask, values);
	xcb_map_window(conn, win);
	xcb_flush(conn);

	while ((event = xcb_wait_for_event(conn))) {
		switch (event->response_type & ~0x80) {
		case XCB_EXPOSE:
			on_xcb_expose(event);
			break;
		case XCB_BUTTON_PRESS:
			on_xcb_button_press(event);
			break;
		case XCB_BUTTON_RELEASE:
			on_xcb_button_release(event);
			break;
		case XCB_MOTION_NOTIFY:
			on_xcb_motion_notify(event);
			break;
		case XCB_ENTER_NOTIFY:
			on_xcb_enter_notify(event);
			break;
		case XCB_LEAVE_NOTIFY:
			on_xcb_leave_notify(event);
			break;
		case XCB_KEY_PRESS:
			on_xcb_key_press(event);
			break;
		case XCB_KEY_RELEASE:
			on_xcb_key_release(event);
			break;
		default:
			printf("Unknown event: %d\n", event->response_type);
			break;
		}

		free(event);
	}

	return 0;
}
