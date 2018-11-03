#include <stdio.h>

int main (int argc, char **argv) {
	int x = 1;
	printf ("and: %i\n", (x & 1));
	printf ("or: %i\n", (x | 1));
	printf ("xor: %i\n", (x ^ 1));
	printf ("xor: %i\n", (x & ~(1)));
	printf ("xor: %i\n", (x | ~(1)));
	printf ("xor: %i\n", (x ^ ~(1)));
	return 0;
}

