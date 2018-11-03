#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <pthread.h>

#define NUM_THREADS 100

void *calculate_square(void *arg)
{
	double *result = malloc(sizeof(double));
	*result = sqrt(*((int *)arg));
	return (void *)result;
}

int main()
{
	pthread_t threads[NUM_THREADS];
	int       nums[NUM_THREADS];

	int i;
	for (i=0; i < NUM_THREADS; i++) {
		nums[i] = i;
	}

	for (i=0; i < NUM_THREADS; i++) {
		pthread_create(&threads[i], NULL, calculate_square,
		(void *)&nums[i]);
	}

	printf("Calculating...\n");
	for (i=0; i < NUM_THREADS; i++) {
		void *result;

		pthread_join(threads[i], &result);

		printf("sqrt %i = %f\n", nums[i], *((double *)result));
		free(result);
	}

	return 0;
}

