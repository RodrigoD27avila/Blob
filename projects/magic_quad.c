#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int table[16];

int contains(int *table, int number)
{
	int i;
	for (i=0; i<16; i++) {
		if (table[i] == number) {
			return 1;
		}
	}

	return 0;
}

void try(int *table)
{
	int i;
	for(i=1; i<=16;i++) {

		if (contains(table, 1)) {
			continue;
		}
	}
}

int main()
{
	memset(table, 0, 16 * sizeof(int));
	
}
