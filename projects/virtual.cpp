#include <iostream>

class foo {
  public:
	virtual void do_this() const = 0;
};

class bar : public foo {
  public:
	typedef foo super;

	virtual void do_this() const override {
		std::cout << "do_this from bar" << std::endl;
	}
};

class boo : public bar {
  public:
	virtual void do_this() const override {
		std::cout << "do_this from boo" << std::endl;
	}

	const int operator[](int index) {
		std::cout << "const int operator" << std::endl;
		return 1;
	}

	const int operator[](int index) const {
		std::cout << "const int operator const" << std::endl;
		return 1;
	}
};

void printf_virtual(const foo *f)
{
	f->do_this();
}

void print_colchetes(boo &b)
{
	int a = b[80];
}


int main()
{
	boo b;
	printf_virtual(&b);
	print_colchetes(b);
}
