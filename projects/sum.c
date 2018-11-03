#include <stdio.h>

int main()
{
	unsigned long long int i, c = 0;
	for (i=1; i <= 548000; i++) {
		c += i;	
	}

	printf("%Lu\n", c);

	return 0;
}
