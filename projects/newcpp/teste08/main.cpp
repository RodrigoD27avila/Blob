#include <iostream>
using namespace std;

class Foo {
public:
	void foo_print()
	{
		cout << "foo_print" << endl;
	}
private:
	void foo_reprint()
	{
		cout << "foo_reprint" << endl;
	}
};

class Bar : private Foo {
public:
	void bar_print()
	{
		foo_print();
	}	
};

int main()
{
	Bar b;
	b.bar_print();
}
