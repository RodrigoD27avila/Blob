#include "myotherclass.h"

#include <iostream>

namespace MyNamespace {

MyOtherClass::MyOtherClass()
	: MyClass(10, 10, 10, 10) 
{
}

MyOtherClass::~MyOtherClass()
{
	using std::cout;
	cout << "MyOtherClass Destructed\n";
}

void MyOtherClass::print_vars()
{
	using std::cout;
	cout << a << "\n"
		<< b << "\n"
		<< c << "\n"
		<< d << "\n";
}

} // end MyNamespace
