#include <stdio.h>

typedef struct
{
	int a, b, c, d;
} Foo;

typedef struct
{
	Foo *ff;
} Bar;


void new_foo(Bar *bar, int a, int b, int c, int d)
{
	Foo f = {a, b, c, d};
	bar->ff = &f;
}

void iplus()
{
	static int i;
	printf("%i\n", i);
	i+=1;
}

int main()
{
	Bar b1 = {0};
	Bar b2 = {0};

	static int a,b,c,d;

	new_foo(&b1, 1, 2, 3, 4);
	printf("b1 = %i, %i, %i, %i\n", b1.ff->a, b1.ff->b, b1.ff->c, b1.ff->d);

	new_foo(&b2, 2, 3, 4, 5);
	printf("b1 = %i, %i, %i, %i\n", b1.ff->a, b1.ff->b, b1.ff->c, b1.ff->d);
	printf("b2 = %i, %i, %i, %i\n", b2.ff->a, b2.ff->b, b2.ff->c, b2.ff->d);
	
	new_foo(&b2, a, b, c, d);
	printf("b2 = %i, %i, %i, %i\n", b2.ff->a, b2.ff->b, b2.ff->c, b2.ff->d);

	a = 10;
	b = 20;
	c = 30;
	d = 40;
	
	printf("b2 = %i, %i, %i, %i\n", b2.ff->a, b2.ff->b, b2.ff->c, b2.ff->d);

	iplus();
	iplus();
	iplus();
	iplus();
	iplus();
	iplus();
	iplus();
}
