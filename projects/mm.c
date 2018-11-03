#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	int mem[32];
	int i;

	for (i=0; i<32; i++) {
		printf("%i ", mem[i]);
	}
	printf("\n");
	memset(mem, 0, 32 * sizeof(int));
	for (i=0; i<32; i++) {
		printf("%i ", mem[i]);
	}
	printf("\n");

	int a[] = {10, 11, 13};
	int b[3];

	printf("%p %p\n", a, b);
	return 0;
}
