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

    GC gc;

    XGCValues values;
    unsigned long valuemask = 0;

    values.foreground = white_pixel;
    values.line_width = 1;
    values.line_style = LineSolid;

    valuemask = GCForeground|GCLineWidth|GCLineStyle;

    gc = XCreateGC(dpy, win, valuemask, &values);

/*
    XSelectInput(dpy, win, ButtonPressMask|StructureNotifyMask|ExposureMask);
    XSetForeground(dpy, gc, black_pixel);
    XSetBackground(dpy, gc, white_pixel);
    XSetFillStyle(dpy, gc, FillSolid);
    XSetLineAttributes(dpy, gc, 2, LineSolid, CapRound, JoinRound);
*/

    XSelectInput(dpy, win, ButtonPressMask|StructureNotifyMask|ExposureMask);

    while (1)
    {
        XNextEvent(dpy, &ev);
        switch(ev.type)
        {
            case Expose:
                XDrawPoint(dpy, win, gc, 5, 5);
                XDrawLine(dpy, win, gc, 20, 20, 40, 100);
                int x = 30, y = 30;
                int h = 15, w = 45;

                int angle1 = 0, angle2 = 2.109;
                XDrawArc(dpy, win, gc, x-(w/2), y-(h/2), w, h, angle1, angle2);
                XDrawArc(dpy, win, gc, 50-(15/2), 100-(15/2), 15, 15, 0, 360*64);
                {
                    XPoint points[] = {
                        {0 , 0 },
                        {15, 15},
                        {0 , 15},
                        {0 , 0 }
                    };
                    int npoints = sizeof(points)/sizeof(XPoint);
                    XDrawLines(dpy, win, gc, points, npoints, CoordModeOrigin);
                }
                XDrawRectangle(dpy, win, gc, 120, 150, 50, 60);
                XFillRectangle(dpy, win, gc, 60, 150, 50, 60);
                break;
            case ButtonPress:
                XCloseDisplay(dpy);
                return 0;
        }
    }
}
