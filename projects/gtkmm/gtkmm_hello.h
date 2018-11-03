#ifndef GTKMM_HELLO_H
#define GTKMM_HELLO_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window
{
public:
    HelloWorld();
    virtual ~HelloWorld();

protected:
    void on_button_clicked();
    Gtk::Button m_button;
};

#endif /*GTKMM_HELLO_H*/
