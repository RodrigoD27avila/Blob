#include <iostream>

#include "cppteste.h"

class Foo {
public:
	void print(const char *str) {
		std::cout << str << std::endl;
	}
};

Foo f;

extern "C" void printf_with_cout(const char *str)
{
	f.print(str);
}

extern "C" void *get_class_pointer()
{
	return (void *)&f;
}
