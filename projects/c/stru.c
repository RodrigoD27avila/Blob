#include <stdio.h>
#include <stdlib.h>

typedef unsigned int    uint;
typedef unsigned long   ulong;

uint soma (uint a, uint b)
{
	return a + b;
}

typedef struct __t _t;

struct __t 
{
	uint a;
	uint b;
	uint (*f) (uint, uint);
};

static _t t =
{
	.a = 10,
	.b = 20,
	.f = soma
};

int main (int argc, char **argv)
{
	printf ("a = %i | b = %i || soma = %i\n", t.a, t.b, t.f(t.a,t.b));
	return (EXIT_SUCCESS);
}
