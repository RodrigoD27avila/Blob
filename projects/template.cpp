#include <iostream>

class Bar
{};
class Boo : public Bar
{};


template<typename T> class Foo
{
public:
    T id;
    T name;

public:
    Foo(const T &name, const T &id);

private:
    Foo(const Foo &foo){}
    Foo &operator =(const Foo<T> &foo);
};

int main()
{
    Bar bar;
    Boo boo;

    Foo<Bar> bb(boo, bar);

    return 0;
}

template<typename T> Foo<T>::Foo(const T &name, const T &id)
{
}

