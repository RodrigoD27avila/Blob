#include <stdio.h>

static int table[20];

int main()
{
	int i, j;
	for (i=0; i<10; i++) {
		for (j=0; j<10; j++) {
			table[(i + j)] += 1;
		}
	}

	for (i=0; i < 20; i++) {
		printf("[%i] = %i\n", i, table[i]);
	}

	return 0;
}
