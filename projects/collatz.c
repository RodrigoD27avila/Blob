#include <stdio.h>

int main()
{
	int i;
	for (i=1; i<=10; i++) {
	int p = i;
	do {
		if ((p % 2) == 0) {
			p /= 2;
		}
		else {
			p *= 3;
			p += 1;
		}

		printf("%i ", p);
	} while (p != 1);
	printf("\n");
	}
}
