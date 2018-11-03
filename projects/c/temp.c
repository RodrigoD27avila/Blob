#include <stdio.h>

int
main ()
{
	int a = 10;
	int b = 8;

	printf ("a=%i, b=%i\n", a, b);
	a ^= b;
	printf ("a=%i, b=%i\n", a, b);
	b ^= a;
	printf ("a=%i, b=%i\n", a, b);
	a ^= b;
	printf ("a=%i, b=%i\n", a, b);
	return 0;
}
