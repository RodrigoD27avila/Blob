#include <iostream>
using namespace std;

class Foo {
public:
	Foo() { cout << "Foo allocated at " << this << endl;
	a=10;b=11;c=12;d=13;
	}
	~Foo() { cout << "Foo deleted" << endl;}
	int a, b, c, d;
};

class Bar {
public:
	Bar();
	~Bar();
	void setfoo(const Foo &foo);
	void printfoo();
private:
	Foo foo;
	Foo *foo2;
};

Bar::Bar()
{
	foo2 = new Foo();
}

Bar::~Bar()
{
	delete foo2;
}

void Bar::setfoo(const Foo &foo)
{
	Bar::foo = foo;
}

void Bar::printfoo()
{
	cout << Bar::foo.a << endl
		<< Bar::foo.b << endl
		<< Bar::foo.c << endl
		<< Bar::foo.d << endl;
}


int main()
{
	cout << "init main" << endl;
	Bar b;
	{
		Foo f1;
		b.setfoo(f1);
	}

	b.printfoo();
}
