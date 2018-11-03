#include <iostream>
#include <list>
#include <initializer_list>

template<class MediaTypeFrame>
    void play_frame(const MediaTypeFrame &f)
{
    std::cout << f << std::endl;
}

template<class MediaType>
    void play(const MediaType &m)
{
    for (auto f : m) {
            play_frame(f);
    }
}

int main()
{
    std::list<std::string> v {"do", "re", "mi", "fa", "sol"};
    play(v);
}
