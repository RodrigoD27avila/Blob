#include <stdio.h>

int main()
{
	int i;
	for (i=1; i<32000; i++) {
		int x = i;
		printf(">> X = %i\n", i);
		while (x >= 0) {
			x &= (x+1);
			printf("\t>> X = %i\n", x);
			x--;
		}
	}
}
