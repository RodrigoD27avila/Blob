#include <iostream>
using namespace std;

class Foo
{
	int a;
public:
	Foo() : a(10) {}
	int getA() {return a;}
};


int main()
{
	Foo *f = new Foo;

	cout << f << endl;
	int a = f->getA();

	cout << &a << endl;

	cout << f->getA() << endl;
	delete f;
	cout << f->getA() << endl;

	cout << f << endl;
	a = f->getA();
	cout << &a << endl;

	a = Foo().getA();

	cout <<  &a<< endl;


	int b[2] = {10, 10};

	cout << &b[0] << endl;
	cout << &b[1] << endl;

	int g = *(&(b[0]));
	int h = *(&(b[1]));

	cout << &g << endl;
	cout << &h << endl;

	if (g == h)
	{
		cout << "IGUAL" << endl;
	}
	else
	{
		cout << "NOT IGUAL" << endl;
	}


	return 0;
}
