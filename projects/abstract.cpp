#include <iostream>
using namespace std;

class Foo;
class Bar;

class Foo {
public:
	Foo() {this->i=10;}
	inline int getI() {return i;}
private:
	int i;
	friend class Bar;
	
};

class Bar : public Foo {
public:
	Bar() {i+= 10;}	
};

int main()
{
	Bar b;
	cout << b.getI() << endl;
}
