#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <stdio.h>
#include <time.h>

#define XSIZE 500
#define YSIZE 500
#define UPDATE_RATE 0.05     // update rate in seconds

// Demonstrate how to display a pixel buffer in FLTK

// WINDOW CLASS TO HANDLE DRAWING IMAGE
class MyWindow : public Fl_Double_Window {
    unsigned char pixbuf[YSIZE][XSIZE][3];              // image buffer

    // FLTK DRAW METHOD
    void draw() {
        fl_draw_image((const uchar*)&pixbuf, 0, 0, XSIZE, YSIZE, 3, 
XSIZE*3);
    }

    // TIMER CALLBACK: CALLED TO UPDATE THE DRAWING
    static void RenderImage_CB(void *userdata) {
        MyWindow *win = (MyWindow*)userdata;
        win->RenderImage();
        Fl::repeat_timeout(UPDATE_RATE, RenderImage_CB, userdata);
    }

public:
    // CTOR
    MyWindow(int w, int h, const char *name=0) : 
Fl_Double_Window(w,h,name) {
        end();
        RenderImage();                   // show first drawing
        // Start timer updating
        Fl::add_timeout(UPDATE_RATE, RenderImage_CB, (void*)this);
    }

    // PLOT A PIXEL AS AN RGB COLOR INTO THE PIXEL BUFFER
    void PlotPixel(int x, int y, unsigned char r, unsigned char g, 
unsigned char b) {
        pixbuf[y][x][0] = r;
        pixbuf[y][x][1] = g;
        pixbuf[y][x][2] = b;
    }

    // MAKE A NEW PICTURE IN THE PIXEL BUFFER, SCHEDULE FLTK TO DRAW IT
    void RenderImage() {
        static unsigned char drawcount = 0;
        for ( int x=0; x<XSIZE; x++ )
            for ( int y=0; y<YSIZE; y++ )
                PlotPixel(x, y, x+drawcount, y+drawcount, 
x+y+drawcount);
        ++drawcount;
        redraw();
    }
};

int main(int argc, char**argv) {
    Fl::visual(FL_RGB);         // prevents dithering on some systems
    MyWindow *win = new MyWindow(XSIZE, YSIZE);
    win->show();
    return(Fl::run());
}
