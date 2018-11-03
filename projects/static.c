#include <stdio.h>

void foo()
{
	static int cc;
	printf("%i\n", cc++);
}

int main()
{
	foo();
	foo();
	foo();
	foo();
	foo();
	foo();
	return 0;
}
