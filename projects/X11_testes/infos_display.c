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

    int screen_num;
    int screen_width;
    int screen_height;
    Window root_window;
    unsigned long white_pixel;
    unsigned long black_pixel;

    screen_num = DefaultScreen(display);
    screen_width = DisplayWidth(display, screen_num);
    screen_height = DisplayHeight(display, screen_num);

    root_window = RootWindow(display, screen_num);
    white_pixel = WhitePixel(display, screen_num);
    black_pixel = BlackPixel(display, screen_num);

    printf("screen_num = %i\n", screen_num);
    printf("screen_width = %i\n", screen_width);
    printf("screen_height = %i\n", screen_height);
    printf("white_pixel = %lu\n", white_pixel);
    printf("black_pixel = %lu\n", black_pixel);

    XCloseDisplay(display);
    return 0;
}
