#include <stdio.h>

struct MyStruct {
	int a, b, c, d;
};

int main()
{
	MyStruct a = {1,2,3, 4};
	MyStruct b = a;

	printf("%i, %i, %i, %i\n", a.a, a.b, a.c, a.d);
	printf("%i, %i, %i, %i\n", b.a, b.b, b.c, b.d);

}
