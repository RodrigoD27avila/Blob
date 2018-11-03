#include <iostream>

class Foo
{
private:
    int a, b, c;

public:
    struct fff
    {
        int a, b, c;
        fff() : a(a), b(b), c(c) {};
    };
};

int main()
{
    struct fff f = Foo::fff();
    return 0;
}
