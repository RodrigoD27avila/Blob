#include <iostream>
#include <string>

using std::string;
using std::cout;

struct Bar
{
    int a, b, c;
};

class Foo
{
public:

    Foo();
    ~Foo();

    void configureVars(int x, int y, int z);
    void modifyName(Bar &mybar);
    
private:    

    int x, y, z;
    
};

Foo::Foo()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Foo::~Foo() {}

void Foo::configureVars(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Foo::modifyName(Bar &bar)
{
    bar.a = 10;
    bar.b = 10;
    bar.c = 10;
}

int main(int argc, char **argv)
{
    Bar b = {0, 0, 0};

    Foo f;
    f.configureVars(10, 10, 10);
    f.modifyName(b);

    return 0;
}
