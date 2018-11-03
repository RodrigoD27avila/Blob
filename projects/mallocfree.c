#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	free(a);
	a = b;
	b = NULL;
	free(a);
	return 0;
}
