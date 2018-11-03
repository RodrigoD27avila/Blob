#include <iostream>
#include <tuple>
#include <initializer_list>

int main()
{
    auto a = {1,2, 3, 4, 5, 6};
    auto b = std::make_tuple(1, "4", 78.90f);
    int g;
    std::string h;
    float i;
    std::tie(g, h, i) = b;
}
