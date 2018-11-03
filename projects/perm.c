#include <stdio.h>

int main()
{
	int i, j = 0;
	for (i=10; i>=1; i--) {
		j+=i;
	}

	printf("%i\n", j);
}
