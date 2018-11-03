#include <stdio.h>

int main()
{
	int i;

	#pragma omp parallel for
	for (i=0; i<200; i++) {
		printf("%i\n", i);
	}
	return 0;
}
