#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int &ref_a = a;
    int *poi_a = &a;

    cout << "value a: " << a << endl;
    cout << "ref   a: " << ref_a << endl;
    cout << "poi   a: " << *poi_a << endl;

    a = 20;
    cout << "-----------" << endl;
    cout << "value a: " << a << endl;
    cout << "ref   a: " << ref_a << endl;
    cout << "poi   a: " << *poi_a << endl;

    int b = 30;
    ref_a = b;

    cout << "-----------" << endl;
    cout << "value a: " << a << endl;
    cout << "ref   a: " << ref_a << endl;
    cout << "poi   a: " << *poi_a << endl;

    int c = 40;
    poi_a = &c;
    cout << "-----------" << endl;
    cout << "value a: " << a << endl;
    cout << "ref   a: " << ref_a << endl;
    cout << "poi   a: " << *poi_a << endl;
    cout << "-----------" << endl;
    return 0;
}
