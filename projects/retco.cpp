#include <iostream>
using namespace std;

class Foo {
public:
	Foo();
};

Foo::Foo()
{
	return;
}

int main()
{
	Foo *foo = new Foo();
	cout << foo << endl;
	return 0;
}
