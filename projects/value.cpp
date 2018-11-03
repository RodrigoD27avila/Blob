#include <iostream>
#include <string>
#include <stdlib.h>

class Foo
{
public:
    std::string name;
};

void change(Foo &f)
{
    Foo *f2 = new Foo();
    f2->name = "Luigi";
    std::cout << "E: " << f2 << '\n';
    f = *f2;
    delete f2;
}

int main()
{
    Foo g;
    {
        Foo f = g;
        f.name = "Mario";
//    change(f);
        std::cout << "E: " << &f << '\n';
        std::cout << f.name << '\n';
    }
    g.name = "kkkkk";
    std::cout << g.name << '\n';

    Foo fl;
    Foo &fk = fl;

    fk.name = "Marieta";

    std::cout << fk.name << '\n';
    std::cout << fl.name << '\n';

    return 0;
}
