#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Tile.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/gl.h>
//
// Example of how to make a 4 port tiled GL window
// ting/erco 1.0
//
class Viewport : public Fl_Gl_Window {
    void RectLine(int x1, int y1, int x2, int y2) {
        glBegin(GL_LINE_LOOP);
        glVertex2s(x1, y1); glVertex2s(x2, y1);
        glVertex2s(x2, y2); glVertex2s(x1, y2);
        glEnd();
    }
protected:
    void draw() {
        if ( !valid() ) {
            // First time? init viewport, etc.
            valid(1);
            glLoadIdentity();
            glViewport(0, 0, w(), h());
            glOrtho(-w(), w(), -h(), h(), -1, 1);
        }
        // Clear screen
        glClear(GL_COLOR_BUFFER_BIT);
        // Draw white 'X'
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINE_STRIP); glVertex2f(w(),  h()); glVertex2f(-w(), 
-h()); glEnd();
        glBegin(GL_LINE_STRIP); glVertex2f(w(), -h()); glVertex2f(-w(),  
h()); glEnd();
        // Draw yellow border last, around the outer edge
        glColor3f(1.0, 1.0, 0.0);
        RectLine(-w()+1, -h()+1, w()-1, h()-1);
    }
public:
    Viewport(int x, int y, int w, int h, char* l=0) : Fl_Gl_Window(x, 
y, w, h, l) {
        end();
    }
};

class Layout:public Fl_Tile {
private:
    Viewport *toplft, *toprig, *botlft, *botrig;
protected:
    // Custom resize behavior : keep viewports proportional during resize
    void resize(int X, int Y, int W, int H) {
        // Get old proportions so we can preserve through resize
        float dw = (float)toplft->w() / w();
        float dh = (float)toplft->h() / h();
        // Carefully construct new edges of ports, keeping proportions
        int xlef = 0, xmid = (int)(W * dw + 0.5), xrig = W;
        int ytop = 0, ymid = (int)(H * dh + 0.5), ybot = H;
        int wlef = xmid - xlef, wrig = xrig - xmid;
        int htop = ymid - ytop, hbot = ybot - ymid;
        // Resize our widget via Fl_Widget (to prevent children resizing)
        Fl_Widget::resize(X, Y, W, H);
        // Resize children with custom computations
        toplft->resize(xlef, ytop, wlef, htop);
        toprig->resize(xmid, ytop, wrig, htop);
        botlft->resize(xlef, ymid, wlef, hbot);
        botrig->resize(xmid, ymid, wrig, hbot);
    }

public:
    Layout(int x, int y, int w, int h) : Fl_Tile(x, y, w, h) {
        box(FL_BORDER_BOX);
        color(FL_RED);          // (shouldn't be seen)
        // Carefully construct edges of ports
        int xlef = 0, xmid = w/2, xrig = w;
        int ytop = 0, ymid = h/2, ybot = h;
        int wlef = xmid - xlef, wrig = xrig - xmid;
        int htop = ymid - ytop, hbot = ybot - ymid;
        // Create the 4 ports
        toplft = new Viewport(xlef, ytop, wlef, htop);
        toprig = new Viewport(xmid, ytop, wrig, htop);
        botlft = new Viewport(xlef, ymid, wlef, hbot);
        botrig = new Viewport(xmid, ymid, wrig, hbot);
        end();
    }
};

int main() {
    Fl_Double_Window *win = new Fl_Double_Window(800, 500);
    Layout *layout = new Layout(0, 0, win->w(), win->h());
    win->resizable(layout);
    win->end();
    win->show();
    return(Fl::run());
}
