#include <gtkmm.h>

class MyWindow : public Gtk::Window
{
public:

    Gtk::Button bt1;

    MyWindow() : Gtk::Window(Gtk::WINDOW_TOPLEVEL)
    {
        set_border_width(10);

        bt1.set_label("Button");
        add(bt1);
    }
    ~MyWindow() {}

    bool on_delete_event(GdkEventAny *event)
    {
        Gtk::Main::quit();
        return false;
    }

};

int main(int argc, char **argv)
{
    Gtk::Main kit(argc, argv);

    MyWindow window;
    window.show_all();

    Gtk::Main::run();
    return 0;
}
