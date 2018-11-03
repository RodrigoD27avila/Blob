#include <iostream>

class Foo {
public:
	int a;
};

class Bar : public Foo {
public: int b;
};


Foo fuck()
{
	Bar b;
	b.a = 10;
	b.b = 10;
	return b;
}

int main()
{

Foo f = fuck();
std::cout << sizeof(Bar) << std::endl;
std::cout << sizeof(Foo) << std::endl;

Bar b = f;

}
