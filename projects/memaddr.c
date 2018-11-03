#include <stdio.h>
#include <stdlib.h>

typedef unsigned long UL;

int main()
{
	UL *pt  = malloc(4000);
	UL **pp = (UL **)pt;

	UL a = 1000;
	UL *p  = (UL *)a;

	void *foo = malloc(16);
	printf("%p\n", foo);
	printf("%lu\n\n", (UL)foo);

	UL myul = 526;
	UL *num = &myul; //malloc(sizeof(UL));
//	*num = 155;
	*pt = (UL) num;

	printf(">> %p\n", num);
	printf(">> %lu\n", (UL)*(*pp));
	
	free(foo);
	free(pt);
	
	return 0;
}
