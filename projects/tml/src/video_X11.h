#ifndef VIDEO_X11_H
#define VIDEO_X11_H

#include "window_priv.h"

#include <X11/Xlib.h>

/*
* This struct contains informations to create
* a new window on X11 enviroment.
*/
struct tml_object_priv_t
{
    Display *dpy;

    int screen_num;
    int root_width;
    int root_height;

    Window root_window;
    unsigned long white_pixel;
    unsigned long black_pixel;

};

struct _tml_window_priv_t
{
    Display *dpy;
    Window parent;

    int screen_number;
    int depth;
    unsigned int border;

    unsigned int cl; /*class*/
    Visual *vi;      /*visual*/

    Mask value_mask;
    XSetWindowAttributes att; /*attributes*/

};

#endif /*VIDEO_X11_H*/
