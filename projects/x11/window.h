#ifndef WINDOW_H
#define WINDOW_H

#include <stdlib.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

struct _window_t
{
    Display *dpy;
    Window  parent;

    int screen_number;

    int x, y;
    unsigned int width;
    unsigned int height;
    int border;

    int depth;
    unsigned int cl;

    Visual *vi;
    Mask valuemask;
    XSetWindowAttributes attributes;
};
typedef struct _window_t window_t;

window_t *window_new();
Window create_window(window_t *win, int x, int y, unsigned int w,
        unsigned int h);

#endif /*WINDOW_H*/
