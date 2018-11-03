#include <iostream>
using namespace std;

class Foo {
public:
	Foo();
	Foo(int i);
private:
	int i;
};

Foo::Foo() : i(0)
{
	cout << "Foo() initialized" << endl;
}

Foo::Foo(int i): i(i)
{
	cout << "Foo(int) initialized" << endl;
}

class Bar {
public:
	 Bar();

private:
	Foo f;
};

Bar::Bar() : f(Foo(8))
{}

int main()
{
	Bar b;
	return 0;
}
