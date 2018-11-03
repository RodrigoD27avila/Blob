#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	int *iptr = malloc(10 * sizeof(int));
	printf ("%p", &iptr);
	return 0;
}
