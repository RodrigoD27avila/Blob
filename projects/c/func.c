#include <stdio.h>

struct blar
{
  int bug;
  int gbu;
  int ugb;
};

void enc_foo(int *a)
{
	*a += 1;
}

int
main (int argc, char **argv)
{
	int foo = 0;

	while (foo <= 10)
	{
		printf ("%i\n", foo);
		enc_foo (&foo);
	}
	
	foo.bug;

	return 0;
}
