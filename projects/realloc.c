#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p = calloc(4, 10);
	int *d = realloc(p, 20*4);

	printf("%p %p", p, d);


}
