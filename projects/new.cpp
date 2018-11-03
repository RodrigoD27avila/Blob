#include <stdlib.h>

#include <iostream>
#include <new>


using namespace std;

class Foo {
public:
	Foo();
	~Foo();	

	static void *operator new(size_t size);
	static void operator delete(void *p);
};

Foo::Foo()
{
	cout << "Foo allocated at: " << this << endl;
}

Foo::~Foo()
{
	cout << "Foo deallocated" << endl;
}

void *Foo::operator new(size_t size)
{
	void *p = malloc(size);
	return p;
}

void Foo::operator delete(void *p)
{
	free(p);
}

int main()
{
	Foo f;
	return 0;
}
