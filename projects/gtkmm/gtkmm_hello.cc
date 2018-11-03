#include "gtkmm_hello.h"

#include <iostream>
#include <gtkmm/main.h>

HelloWorld::HelloWorld() : m_button("Hello World")
{
	set_border_width(10);
	m_button.signal_clicked().connect(sigc::mem_fun(*this,
            &HelloWorld::on_button_clicked));

    add(m_button);
    m_button.show();
}


HelloWorld::~HelloWorld()
{
}

void HelloWorld::on_button_clicked()
{
    std::cout << "Hello World" << std::endl;
}


int main(int argc, char **argv)
{
	Gtk::Main kit(argc, argv);

	HelloWorld helloworld;
	Gtk::Main::run(helloworld);
    return 0;
}
