#include <stdio.h>

int main()
{
	int i, t = 0;
	for(i=1; i <= 512; i++) {
		t += i;
	}

	printf("TOTAL: %i\n", t);
	return 0;
}
