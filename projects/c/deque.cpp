#include <iostream>
#include <deque>

class Foo {
public:
	int *foo;
	Foo() {
		foo  = new int[10];
	}
	~Foo() {
		delete[] foo;
	}
};

int main()
{
	Foo *f = new Foo();
	delete f;

	std::deque<Foo *> *d = new std::deque<Foo *>();
	d->push_back(new Foo());
	d->push_back(new Foo());
	d->push_back(new Foo());
	d->push_back(new Foo());
	d->push_back(new Foo());

	std::deque<Foo *>::iterator it;
	int i=0;
	for (it=d->begin(); it != d->end(); it++) {
		std::cout << i++ << '\n';
		delete (*it);
	}

	delete d;	
	return 0;
}

