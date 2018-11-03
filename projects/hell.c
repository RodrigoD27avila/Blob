#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int U64;

int main()
{
	U64 i = 0;
	printf("I = %lu", (i-1));
	void *data = malloc(7200);
	printf("%lu\n", sizeof(*data));
	return 0;
}
