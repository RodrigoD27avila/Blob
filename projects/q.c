#include <stdio.h>

inline int foo() __attribute__((always_inline));
int foo()
{
	int a = 10;
	int b = 90;
	return a+b;
}

int bar()
{
	return foo();
}

int boo()
{
	return bar();
}

int main()
{
	return boo();
}
