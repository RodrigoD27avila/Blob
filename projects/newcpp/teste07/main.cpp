#include <cstdio>

struct MyValue {
	int a, b, c, d;
};

class Foo {
public:
	MyValue v;

	Foo(MyValue v) : v(v)
	{}

	void print_ptr();
};

void Foo::print_ptr()
{
	printf("%p\n", &v);
}

static Foo *f;

int main()
{
	MyValue val = {1,2,3,4};
	f = new Foo(val);
	printf("%p\n", &val);
	f->print_ptr();
	delete f;
}
