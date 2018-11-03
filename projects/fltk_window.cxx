#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

#include <stdio.h>

class My_Button : Fl_Button
{
    static void foo_CB(Fl_Widget* w, void* data)
    {
        w->label("&No Click!!");
        w->callback(bar_CB, NULL);
    }

    static void bar_CB(Fl_Widget* w, void* data)
    {
        w->label("&Click!!");
        w->callback(foo_CB, NULL);
    }

    int handle(int event)
    {
       switch(event) {
            case FL_PUSH:
                printf("%d, FL_PUSH\n", event);
                down_color(0xd0d0d000);
                value(1);
                redraw();
                do_callback();
                return FL_PUSH;
            case FL_RELEASE:
                printf("%d, FL_RELEASE\n", event);
                value(0);
                redraw();
                return FL_RELEASE;
            case FL_ENTER:
                printf("%d, FL_ENTER\n", event);
                color(0xd0d0d000);
                box(FL_UP_BOX);
                redraw();
                return FL_ENTER;
            case FL_LEAVE:
                printf("%d, FL_LEAVE\n", event);
                color(0xc0c0c000);
                box(FL_FLAT_BOX);
                redraw();
                return FL_LEAVE;
        }
        printf ("%d\n", event);
        return Fl_Widget::handle(event);
    }

public:
    My_Button(int x, int y, int w, int h, const char *label)
        : Fl_Button(x, y, w, h, label)
    {
        color(0xc0c0c000);
        down_color(0xc0c0c000);
        box(FL_FLAT_BOX);
        down_box(FL_DOWN_BOX);
        callback(foo_CB, NULL);
        clear_visible_focus();
    }

};

int main(int argc, char **argv)
{
    Fl_Window *w = new Fl_Window(400, 400, "#######");
    My_Button *bt1 = new My_Button(10,10,100,100, "&Click..");
    My_Button *bt2 = new My_Button(120,120,100,100, "&Click..");

    w->show();
    return Fl::run();
}


