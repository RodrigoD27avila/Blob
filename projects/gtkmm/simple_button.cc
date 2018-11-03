#include <iostream>
#include <gtkmm.h>

void on_button_clicked()
{
    std::cout << "Hello!!!\n";
    Gtk::Main::quit();
}

int main(int argc, char **argv)
{
    Gtk::Main kit(argc, argv);

    Gtk::Window window(Gtk::WINDOW_TOPLEVEL);
    Gtk::Button button("_Hello", true);
    window.add(button);
    window.show_all();

    button.signal_clicked().connect(sigc::ptr_fun(&on_button_clicked));

    Gtk::Main::run();
    return 0;
}
