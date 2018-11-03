#include <stdio.h>

int main()
{
	int i, n = -1;
	for (i=0; i < 100; i++)
	{
		n += (!(i % 10));
		printf("%i, %i\n",  n * 10,  10 * (i % 10));
	}	
}
