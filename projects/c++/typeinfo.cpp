#include <iostream>
#include <typeinfo>
using namespace std;

class Bar
{
    int i;
public:
    Bar() :i(0) {}
};

int main(int arg, char **argv)
{
    int n = 0;
    float m = 0;
    unsigned long long int b = 0;
    string fu = "AAAAAA";
    Bar bar;
    cout << typeid(n).name() << endl;
    cout << typeid(m).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(fu).name() << endl;
    cout << typeid(bar).name() << endl;
    return 0;
}
