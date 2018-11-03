#include <iostream>

template<typename T> struct Foo
{
    T a,b,c;
};



int main(int argc, char **argv)
{
    Foo<int> f;
    f.a = 30;
    f.b = 410;
    f.c = 522;

    std::cout << f.a << std::endl;
    std::cout << f.b << std::endl;
    std::cout << f.c << std::endl;
}
