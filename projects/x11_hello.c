#include <stdio.h>
#include <stdlib.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xresource.h>

void draw(Display *dpy, Window win, unsigned long color)
{
    GC gc = {0};
    gc = XCreateGC(dpy, win, 0, 0);

    XSetForeground(dpy, gc, color);
    XDrawLine(dpy, win, gc, 10, 60, 180, 20);
    XFlush(dpy);
}

int main(int argc, char **argv)
{
    int snum, width, height;
    unsigned long background, border;

    Display *dpy = NULL;

    dpy = XOpenDisplay(NULL);
    if (!dpy)
    {
        fprintf(stderr, "Unable to connect to display.\n");
        exit(EXIT_FAILURE);
    }

    snum       = DefaultScreen(dpy);
    background = BlackPixel(dpy, snum);
    border     = WhitePixel(dpy, snum);

    width  = 320;
    height = 240;

    Window win = {0};
    win = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy),
            0, 0, width, height, 2, border, background);
    
    long mask = ButtonPressMask | StructureNotifyMask | KeyPressMask
            | KeyReleaseMask | KeymapStateMask;

    XSelectInput(dpy, win, mask);
    XMapWindow(dpy, win);
    
    XEvent ev = {0};
    while (1)
    {
        XNextEvent(dpy, &ev);
        switch (ev.type)
        {
            case MapNotify:
            {
                draw(dpy, win, border);
                break;
            }
            
            case KeymapNotify:
            {
                XRefreshKeyboardMapping(&ev.xmapping);
                break;
            }

            case KeyPress:
                break;

            case KeyRelease:
            {
                char string[25];
                int len;
                KeySym keysym;

                len = XLookupString(&ev.xkey, string, 25, &keysym, NULL);
                if (len < 0)
                {
                    if (string[0] == 'r') {string[0] = 'n';};
                    fputs(string, stdout);
                }
                break;
             }
    
            case ConfigureNotify:
            {
                int x_width  = ev.xconfigure.width;
                int x_height = ev.xconfigure.height;

                if (width != x_width || height != x_height)
                {
                    width  = x_width;
                    height = x_height;
                    printf("Size changed to, %i by %i.\n", width, height);
                }
                break;
             }

            case Expose:
            {
                printf("Expose ocurred\n");
                break;
            }

            case ButtonPress:
                XDestroyWindow(dpy, win);
                XCloseDisplay(dpy);
                goto end;
            
        }
    }

end:
    return 0;
}
