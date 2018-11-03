#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <X11/Xlib.h>

int main()
{
    Display *dpy = XOpenDisplay(NULL);
    XEvent ev;

    int screen_num;
    int screen_width;
    int screen_height;

    Window root_window;
    unsigned long white_pixel;
    unsigned long black_pixel;

    screen_num = DefaultScreen(dpy);
    screen_width = DisplayWidth(dpy, screen_num);
    screen_height = DisplayHeight(dpy, screen_num);

    root_window = RootWindow(dpy, screen_num);
    white_pixel = WhitePixel(dpy, screen_num);
    black_pixel = BlackPixel(dpy, screen_num);

    int win_width = screen_width / 3;
    int win_height = screen_height / 3;
    int win_x = 0;
    int win_y = 0;

    Window win = XCreateSimpleWindow(dpy, root_window, win_x, win_y,
                                win_width, win_height, 2,
                                white_pixel, black_pixel);

    XMapWindow(dpy, win);

    XSelectInput(dpy, win, 0b111111111111111111111111);

    while (1)
    {
        XNextEvent(dpy, &ev);
        switch(ev.type)
        {
            case KeyPress:
                printf("KeyPress\n");
                break;
            case KeyRelease:
                printf("KeyRelease\n");
                break;
            case ButtonPress:
                printf("ButtonPress\n");
                break;
            case ButtonRelease:
                printf("ButtonRelease\n");
                break;
            case MotionNotify:
                printf("MotionNotify\n");
                break;
            case EnterNotify:
                printf("EnterNotify\n");
                break;
            case LeaveNotify:
                printf("LeaveNotify\n");
                break;
            case FocusIn:
                printf("FocusIn\n");
                break;
            case FocusOut:
                printf("FocusOut\n");
                break;
            case KeymapNotify:
                printf("KeymapNotify\n");
                break;
            case Expose:
                printf("Expose\n");
                break;
            case GraphicsExpose:
                printf("GraphicsExpose\n");
                break;
            case NoExpose:
                printf("NoExpose\n");
                break;
            case VisibilityNotify:
                printf("VisibilityNotify\n");
                break;
            case CreateNotify:
                printf("CreateNotify\n");
                break;
            case DestroyNotify:
                printf("DestroyNotify\n");
                break;
            case UnmapNotify:
                printf("UnmapNotify\n");
                break;
            case MapNotify:
                printf("MapNotify\n");
                break;
            case MapRequest:
                printf("MapRequest\n");
                break;
            case ReparentNotify:
                printf("ReparentNotify\n");
                break;
            case ConfigureNotify:
                printf("ConfigureNotify\n");
                break;
            case ConfigureRequest:
                printf("ConfigureRequest\n");
                break;
            case GravityNotify:
                printf("GravityNotify\n");
                break;
            case ResizeRequest:
                printf("ResizeRequest\n");
                break;
            case CirculateNotify:
                printf("CirculateNotify\n");
                break;
            case CirculateRequest:
                printf("CirculateRequest\n");
                break;
            case PropertyNotify:
                printf("PropertyNotify\n");
                break;
            case SelectionClear:
                printf("SelectionClear\n");
                break;
            case SelectionRequest:
                printf("SelectionRequest\n");
                break;
            case SelectionNotify:
                printf("SelectionNotify\n");
                break;
            case ColormapNotify:
                printf("ColormapNotify\n");
                break;
            case ClientMessage:
                printf("ClientMessage\n");
                break;
            case MappingNotify:
                printf("MappingNotify\n");
                break;
            case GenericEvent:
                printf("GenericEvent\n");
                break;
            default:
                printf("!!DEFAULT!!\n");
        }
    }
}
