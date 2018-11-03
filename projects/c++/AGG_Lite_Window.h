#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

#include "agg2/agg.h"
#include <math.h>

#ifndef AGG_LITE_WINDOW_DEF
#define AGG_LITE_WINDOW_DEF

typedef unsigned char uchar8;

class AGG_Lite_Window : public Fl_Double_Window {

 public:

  AGG_Lite_Window(int x, int y, int w, int h, char *s);    
     ~AGG_Lite_Window() { delete [] buf; delete rbuf; delete ren; };

 private:

  uchar8 *buf;
  agg::rendering_buffer *rbuf;
     agg::rasterizer ras;
  agg::renderer *ren;

  void draw(void);
  int handle(int event);

  void move_to(double x, double y);
  void line_to(double x, double y);
  void draw_ellipse(double x,  double y, double rx, double ry);  
  void draw_line(double x1, double y1, double x2, double y2, double 
width);
  void clear_buffer(void);
  void blit_buffer(void);
  void render(uchar8 r,uchar8 g,uchar8 b,uchar8 a);
};

#endif

