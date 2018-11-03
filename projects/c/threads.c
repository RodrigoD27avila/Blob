#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *print_hello(void *threadid)
{
	printf("%d: Hello World!\n", (int)threadid);
	pthread_exit(NULL);
}

int main(int argc, char **argv)
{
	pthread_t thread[NUM_THREADS];
	int status, i;

	for (i=0; i <NUM_THREADS; i++) {
		printf("Creating thread %i\n", i);
		status = pthread_create(&thread[i], NULL,
			 print_hello, (void*)i);

		if (status) {
			perror("thread_create");
			exit(EXIT_FAILURE);
		}
	}

	pthread_exit(NULL);
}
