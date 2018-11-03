#include "window.h"
#include "display.h"

window_t *window_new()
{
    window_t *w = malloc(sizeof(window_t));

    w->dpy = get_default_diplay();
    w->screen_number = DefaultScreen(w->dpy);
    w->parent = RootWindow(w->dpy, w->screen_number);
    w->depth  = DefaultDepth(w->dpy, w->screen_number);
    w->cl = InputOutput;
    w->vi = DefaultVisual(w->dpy, w->screen_number);
    w->valuemask = CWEventMask | CWOverrideRedirect;
    w->attributes.event_mask = FocusChangeMask | ButtonPressMask | ButtonReleaseMask | ButtonMotionMask | PointerMotionMask | KeyPressMask | KeyReleaseMask | StructureNotifyMask | EnterWindowMask | LeaveWindowMask;
    w->attributes.override_redirect = False;
    w->border = 0;

    return w;
}

Window create_window(window_t *win, int x, int y, unsigned int w, unsigned int h)
{
    return XCreateWindow(win->dpy, win->parent, x, y, w, h, win->border,
    win->depth, win->cl, win->vi, win->valuemask, &win->attributes);
}
