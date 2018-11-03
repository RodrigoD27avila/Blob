#include <iostream>
#include <memory>

using namespace std;

class Bar
{
public:
	Bar();
	~Bar();
private:
	int kk;
};

class Foo
{

public:
	Foo();
	~Foo();

private:
	int ii;
	int *jj;
	Bar *bb;
};

Bar::Bar()
{
	kk = 10;
}

Bar::~Bar()
{
}

Foo::Foo()
{
	auto_ptr<Bar> bar (new Bar);
	bb = new Bar;
	ii = 0;

	jj = new int;
}

Foo::~Foo()
{
	delete jj;
	delete bb;
}

int main()
{
	Foo f;
	return 0;
}

