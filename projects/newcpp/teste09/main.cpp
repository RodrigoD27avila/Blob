#include <iostream>
using namespace std;

class Foo {
public:
	int a, b, c, d;
};

int main()
{
	Foo f = {
		.a = 1,
		.b = 2,
		.c = 3,
		.d = 4,
	};
}
