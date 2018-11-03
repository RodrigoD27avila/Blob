#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
    sf::Window window(sf::VideoMode(640, 480, 32), "SFML Window",
        sf::Style::Default, sf::ContextSettings(32));

    window.SetFramerateLimit(60);

    while (window.IsOpened())
    {
        sf::Event event;
        while (window.PollEvent(event))
        {
            switch (static_cast<int>(event.Type))
            {
                case sf::Event::Closed:
                    window.Close();
                    break;

                case sf::Event::Resized:
                    std::cout << "Resized\n";
                    break;

                case sf::Event::MouseEntered:
                    std::cout << "Mouse Entered\n";
                    break;
            }
        }

        window.SetActive();
        window.Display();
    }

    return 0;
}
