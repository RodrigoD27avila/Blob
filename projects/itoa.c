#include <stdio.h>

int main()
{
	int val = 50001;
	int base = 10;

	static char buf[32] = {0};
	int i = 30;

	for (; val && i; --i, val /= base)
	{	
		buf[i] = "0123456789abcdef"[val % base];
	}

	printf ("%s\n", &buf[i+1]);
	return 0;
}
