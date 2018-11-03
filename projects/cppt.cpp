#include <iostream>

template<typename T = int>
class Foo
{
public:
    T a, b, c;
};


int main()
{
    Foo<int> f;
    f.a = 10;
    f.b = 110;
    f.c = 1110;
    return 0;
}

