#include <iostream>
using namespace std;

class Foo {
};

class Bar {
};

int main()
{
	Foo f;
	Bar b;
	Foo c;

	if (f == c) {
		cout << "EQUALS" << endl;
	}
	else {
		cout << "NOT EQUALS" << endl;
	}
}




