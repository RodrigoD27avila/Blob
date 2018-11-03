#include "display.h"

Display *get_default_diplay()
{
    Display *dpy;
    dpy = XOpenDisplay(NULL);

    if(dpy == NULL)
    {
        fprintf(stderr, "Cannot connect to X server.");
        exit(EXIT_FAILURE);
    }

    return dpy;
}
