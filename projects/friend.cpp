#include <stdlib.h>
#include <iostream>

class Foo;
class Bar;
class Boo;


class Foo
{
const char* foo;
public:
    Foo() : foo("Foo"){}
    ~Foo(){}
    void print_foo(Bar&);
    void print_foo(Boo&);
};

class Bar
{
const char* bar;
public:
    Bar(): bar("Bar"){}
    ~Bar(){}
    void print_bar();
private:
    friend class Foo;
};

class Boo : public Bar
{
const char* boo;
public:
    Boo() : boo("Boo"){}
    ~Boo(){}
    void print_bar();
private:
    friend class Foo;
};

void Foo::print_foo(Bar& b)
{
    std::cout << Foo::foo << std::endl;
    std::cout << b.bar << std::endl;
}

void Foo::print_foo(Boo& o)
{
    std::cout << Foo::foo << std::endl;
    std::cout << o.boo << std::endl;
}

void Bar::print_bar()
{
    std::cout << Bar::bar << std::endl;
}

void Boo::print_bar()
{
    Bar::print_bar();
    std::cout << Boo::boo << std::endl;
}


int main(int argc, char** argv)
{
    Foo f;
    Bar b;
    Boo o;

    f.print_foo(o);
    std::cout << "------" << std::endl;
    f.print_foo(o);
    std::cout << "------" << std::endl;
    b.print_bar();
    std::cout << "------" << std::endl;
    o.print_bar();
    std::cout << "------" << std::endl;
    return 0;
}
