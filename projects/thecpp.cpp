#include <iostream>

namespace myclasses
{
    class Foo
    {
    public:
        Foo();
        ~Foo();

        void printbar();

    private:
        Bar bar;
    }

    class Bar
    {
    public:
        void set_abc(int a, int b, int c);

    private:
        int a, b, c;
        friend class Foo;
    }

Foo::Foo()
{
    bar.a = 10;
    bar.c = 20;
    bar.d = 30;
}

}

