#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xresource.h>
#include <stdio.h>
int main()
{
    int screenNum, width, height;
    unsigned long background, border;

    Window win1;
    XEvent eve;
    Display *dpy1;

    dpy1 = XOpenDisplay(NULL);
    if (!dpy1)
    {
        fprintf(stderr, "unable to connect to display\n");
        return 7;
    }

    screenNum = DefaultScreen(dpy1);
    background = BlackPixel(dpy1, screenNum);
    border = WhitePixel(dpy1, screenNum);

    width = 200;
    height = 200;

    win1 = XCreateSimpleWindow(dpy1, DefaultRootWindow(dpy1),
                      0, 0, width, height, 2, border, background);

    XSelectInput(dpy1, win1, ButtonPressMask|StructureNotifyMask);
    XMapWindow(dpy1, win1);

    while(1)
    {
        XNextEvent(dpy1, &eve);
        switch (eve.type)
        {
            case ConfigureNotify:
                if(width != eve.xconfigure.width
                    || height != eve.xconfigure.height)
                {
                    width = eve.xconfigure.width;
                    height = eve.xconfigure.height;
                    printf("Size changed to: %i by %i\n", width, height);
                }
                break;
            case ButtonPress:
                XCloseDisplay(dpy1);
                return 0;
        }
    }
}
