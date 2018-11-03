#include "myclass.h"

#include <iostream>

namespace MyNamespace {

MyClass::MyClass(int a, int b, int c, int d)
	: a(a), b(b), c(c), d(d)
{
}

MyClass::~MyClass()
{
	using std::cout;
	cout << "MyClass Destructed\n";
}

} // end MyNamespace

