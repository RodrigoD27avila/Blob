#include <iostream>
#include <vector>
#include <SFML/Window.hpp>

int main()
{
    std::vector<sf::VideoMode> modes = sf::VideoMode::GetFullscreenModes();
    unsigned int i;
    for (i=0; i< modes.size(); ++i)
    {
        sf::VideoMode mode = modes[i];
        std::cout << "Mode #" << i << ": "
                  << mode.Width << "x" << mode.Height << " - "
                  << mode.BitsPerPixel << " bpp" << std::endl;
    }

    sf::Window window(modes[0], "Complex Window.");
    window.Create(modes[0], "Complex Window.", sf::Style::Fullscreen);
    window.SetFramerateLimit(60);

    while (window.IsOpened())
    {
        sf::Event ev;
        while (window.PollEvent(ev))
        {
            if (ev.Type == sf::Event::Closed)
                window.Close();

            if (ev.Type == sf::Event::KeyPressed)
            {
                if (ev.Key.Code == sf::Keyboard::Escape)
                    window.Close();
            }
        }

        window.Clear(sf::Color(0, 255, 255));
        window.SetActive();
        window.Display();

    }

    return 0;
}
