#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

int main()
{
    Display *display;
    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        fprintf(stderr, "Cannot connect to X server.");
        exit(-1);
    }

    XCloseDisplay(display);
    return 0;
}
