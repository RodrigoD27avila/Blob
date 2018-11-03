#include <iostream>
using namespace std;

class Foo;
class Bar;


class Bar {
public:
	Bar();
	void modify();
private:
	friend class Foo;
	int a, b, c, d;
};

Bar::Bar() : a(10), b(11), c(12), d(13)
{ }

void Bar::modify()
{
	a+=1;
	b+=1;
	c+=1;
	d+=1;
}

class Foo {
public:
	Foo(const Bar& bar);
	void printbar();
private:
	Bar bar;
};

Foo::Foo(const Bar& bar) : bar(bar)
{ }

void Foo::printbar()
{
	cout << bar.a << endl;
	cout << bar.b << endl;
	cout << bar.c << endl;
	cout << bar.d << endl;
}

int main()
{
	Bar b;
	Foo f(b);
	f.printbar();
	b.modify();
	Foo f2(b);

	cout << "-------------------------------------" << endl << endl;

	f2.printbar();
	f.printbar();
	
	
	return 0;
}


