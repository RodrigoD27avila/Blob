#include <stdio.h>
#include <stdlib.h>

struct Foo {
	int a;
	int b;
	int c;
};

void garuge(struct Foo **f)
{
	int i;
	for (i=0; i<2; i++) {
		printf("%i\n", f[i]->a);
	}
}

int main()
{
	struct Foo **f  = (struct Foo **)malloc(3 * sizeof(struct Foo));
	int i;
	for (i=0; i<3; i++) {
		f[i] = (struct Foo *)malloc(sizeof(struct Foo));
	}
	garuge(f);
	return 0;
}



