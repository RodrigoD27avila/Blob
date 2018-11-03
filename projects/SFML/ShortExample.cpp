#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    sf::Texture texture;
    if (!texture.LoadFromFile("image.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    sf::Font font;
    if (!font.LoadFromFile("font.ttf"))
        return EXIT_FAILURE;

    sf::Text text("Hello SFML", font, 50);

    sf::Music music;
    if (!music.OpenFromFile("music.ogg"))
        return EXIT_FAILURE;

    music.Play();

    while (window.IsOpened())
    {
        sf::Event event;
        while (window.PollEvent(event))
        {
            if (event.Type == sf::Event::Closed)
                window.Close();
        }

        window.Clear();
        window.Draw(sprite);
        window.Draw(text);
        window.Display();
    }

    return 0;
}
