#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int a, b, c, d, e;
	float f;
} Foo;

int main()
{
	char *buffer = malloc(2 * sizeof(Foo));

	Foo foo1 = {10, 20, 30, 40, 50, 20.8};
	Foo foo2 = {11, 21, 31, 41, 51, 21.8};

	int size = sizeof(Foo);
	memcpy(buffer     , &foo1, size);
	memcpy(buffer+size, &foo2, size);

	Foo *foo3 = (Foo *)buffer;
	Foo *foo4 = (Foo *)(buffer+size);

	printf("%i,%i,%i,%i,%i\n", foo3->a,foo3->b,foo3->c,foo3->d,foo3->e);
	printf("%i,%i,%i,%i,%i\n", foo4->a,foo4->b,foo4->c,foo4->d,foo4->e);
	printf("%f\n", foo3->f);
	printf("%f\n", foo4->f);

	return 0;	
}
