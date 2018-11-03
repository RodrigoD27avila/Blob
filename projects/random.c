#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	
	srand(time(NULL));
	int i;
	for (i=0; i<4; i++) {
		double r = (double)rand() / (double)RAND_MAX;
		printf("%f\n", r);
	}
	return 0;	
}
