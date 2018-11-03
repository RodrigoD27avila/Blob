#include <stdio.h>
#include <stdlib.h>

typedef struct foo foo;
struct foo {
	foo *f1;
	foo *f2;
};

int main() 
{
	static foo f;
	printf("%p\n", &f);
	printf("%p\n", &f.f1);
	printf("%p\n", &f.f2);

	printf("%p\n", f.f1);
	printf("%p\n", f.f2);

	foo *new = f.f1;
	new = malloc(sizeof(new));
	
	printf("%p\n", f.f1);
	printf("%p\n", f.f2);
	
	return 0;
}
