#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *hello_function(void *arg)
{
	int i;
	for (i=0; i< 5; i++) {
		printf("Hello World from thread %i\n", *((int*)arg));
	}

	return NULL;
}

int main()
{
	pthread_t threads[NUM_THREADS];
	int       nums[NUM_THREADS];	

	int i;
	for (i=0; i < NUM_THREADS; i++) {
		nums[i] = i;
		pthread_create(&threads[i], NULL, hello_function,
			(void *)&nums[i]);
	}
	
	for (i=0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}

	return 0;
}
