#include <iostream>

class Foo
{
public:
    template<class T> struct Bar
    {
        T a:1, b:1, c:1;
    };
};

int main()
{
    struct Foo::Bar<unsigned int> r = {1, 1, 1};
    std::cout << r.a << r.b << r.c;
    return 0;
}
