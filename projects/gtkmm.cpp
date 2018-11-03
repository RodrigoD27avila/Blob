#include <gtkmm.h>
#include <gtkmm/window.h>
#include <gtkmm/label.h>

class MyWindow : public Gtk::Window
{
public:
    MyWindow() : Gtk::Window()
    {
        Gtk::Label label("Hello", 10, 10);
        add(label);
    }
};

int main(int argc, char** argv)
{
    Gtk::Main kit(argc, argv);
    MyWindow w;
    Gtk::Main::run(w);
    return 0;
}
