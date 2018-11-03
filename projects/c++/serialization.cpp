#include <iostream>
#include <fstream>
class Foo
{
    int a;
    int b;
    int c;
    char cc;
public:
    Foo() : a(10), b(20), c(30), cc('R') {}
};


int main()
{
    Foo f;
    std::ofstream of("foo.ros", std::ios_base::binary);
    of.write((char*)&f, sizeof(f));

    return 0;
}
