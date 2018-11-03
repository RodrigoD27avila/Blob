#include <stdio.h>

unsigned int swap(unsigned int arg)
{
	unsigned short const *pointer = (unsigned short *)&arg;

	unsigned short hi       = pointer[0];
	unsigned short lo       = pointer[1];

	pointer[1] = hi;
	pointer[0] = lo;

	return arg;
}

int main()
{
	printf("%u", swap(10));
	return 0;
}
