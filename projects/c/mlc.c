#include<stdio.h>

void
main (void)
{
	int i = 0;
	int *ip;
	ip = (int *) malloc(100 * sizeof(int));

	printf("%p\n", ip);
	printf("%x\n",(100 * sizeof(int)));
}

