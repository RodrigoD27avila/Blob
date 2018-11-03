#include <stdio.h>

int main()
{
	unsigned long n1 = 0, n2 = 1, ns = 0;
	int i;

	printf("%lu\n", n1);
	printf("%lu\n", n2);

	for (i=2; i < 500; i++)
	{
		printf("%lu\n", n2);
		ns = n2;
		n2 += n1;
		n1 = ns;
	}

	return 0;
}
