#include <stdio.h>

int main()
{
	unsigned j = 4294967290;
	for (;;)
	{
		printf("%u\n", (++j) % 32);
	}
	return 0;
}
