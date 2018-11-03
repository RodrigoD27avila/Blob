#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

#include "display.h"
#include "window.h"

int main(int argc, char **argv)
{
    window_t *win = window_new();
    Window w = create_window(win, 10, 10, 100, 100);
    XMapWindow(win->dpy, w);

    XSelectInput(win->dpy, w, 0b111111111111111111111111);

    XEvent ev;

    while (1)
    {
        XNextEvent(win->dpy, &ev);
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

    return 0;
}
