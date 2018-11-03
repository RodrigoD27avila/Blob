#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
    sf::Window window(sf::VideoMode(640, 480, 32), "SFML Window",
        sf::Style::Default, sf::ContextSettings(32));

    while (window.IsOpened())
    {
        sf::Event event;
        while (window.PollEvent(event))
        {
            if (event.Type == sf::Event::Closed)
                window.Close();
        }

        window.SetActive();
        window.Display();
    }

    return 0;
}
