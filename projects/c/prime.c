#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int i = 2,  j = 2;
	int c = 0;

	for (; i < 100; i++)
	{
		int k = i;
		for (; j <= k; k--)
		{
			if (k == 1)
				continue;

			if ((i % k) == 0)
			{
				c++;
			}
		}

		if (c > 0)
		{
			printf ("%i is prime\n", i);
		}

		c = 0;
	}
	return (EXIT_SUCCESS);
}
