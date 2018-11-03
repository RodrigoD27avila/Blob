#include <iostream>
using namespace std;

class Foo
{
private:
    int d, e, f;

public:
    int a, b, c;
    Foo();
};

class Bar : public Foo
{
};
