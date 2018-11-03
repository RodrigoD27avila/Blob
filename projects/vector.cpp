#include <list>
using namespace std;


class foo
{
public:
    int a, b, c;
    foo() : a(10), b(20), c(30) {}
};

static bool deletefoo(foo * f)
{
    delete f;
    return true;
}

int main()
{
    list<foo *> *lis = new list<foo *>();
    int i;
    for (i=0; i<100; ++i)
    {
        foo *f1 = new foo();
        lis->push_back(f1);
    }
    lis->remove_if(deletefoo);
    delete lis;
}
