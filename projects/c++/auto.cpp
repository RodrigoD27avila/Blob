#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    auto i = 10;
    cout << typeid(i).name() << endl;
    return 0;
}
