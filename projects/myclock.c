#include <stdio.h>
#include <time.h>

int main()
{
	unsigned int ticks;
	struct timespec start;
	struct timespec now;
	clock_gettime(CLOCK_MONOTONIC, &start);

	int i, j, k;
	for (i=0; i<2000; i++){
	for (j=0; j<1000; j++){
	for (k=0; k<1000; k++){
	}}}

	clock_gettime(CLOCK_MONOTONIC, &now);
	ticks = (now.tv_sec-start.tv_sec) * 1000
		+ (now.tv_nsec-start.tv_nsec) / 1000000;
	
	printf("ticks is %u milliseconds\n", ticks);

	return 0;
}
