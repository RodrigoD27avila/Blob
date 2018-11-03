#include <iostream>
using namespace std;

class Foo {
protected:
	int i;
public:
	Foo(int i) : i(i) {}
};

class Bar : public Foo {
public:
	Bar(int i) : Foo(i)  {}
	void ppp() {cout << i << endl; }
};

int main()
{
	Bar b(10);
	b.ppp();
}
