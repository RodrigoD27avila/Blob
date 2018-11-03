#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

class Foo {
public:
	int a;
	int b;
	int c;

	Foo () {
	}

};

int
main ()
{
	Foo f1;
	f1.a = 10;
	f1.b = 10;
	f1.c = 10;

	Foo f2(f1);

	cout << &f1.a << endl;
	cout << &f1.b << endl;
	cout << &f1.c << endl;

	cout << &f2.a << endl;
	cout << &f2.b << endl;
	cout << &f2.c << endl;
	return 0;
}
