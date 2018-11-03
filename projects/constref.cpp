#include <stdio.h>

struct MyStruct {
	int a, b, c;
};

extern "C" void printf_addr(const MyStruct & func)
{
	printf("%p\n", &func);
}

int main()
{
	MyStruct m = {0, 1, 2};
	printf("%p\n", &m);
	printf_addr(m);
	
}
