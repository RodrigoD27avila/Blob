#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
int shared_data;

void *thread_function( void *arg)
{
	int i;
	for (i=0; i < 10024; i++) {
		pthread_mutex_lock(&lock);
		usleep(1000);
		shared_data++;
		pthread_mutex_unlock(&lock);
	}

	return NULL;
}

int main()
{
	pthread_t thread_ID;
	void      *exit_status;
	int       i;

	shared_data = 0;

	pthread_mutex_init(&lock, NULL);
	pthread_create(&thread_ID, NULL, thread_function, NULL);

	for (i=0; i < 10; i++) {
		sleep(1);
//		pthread_mutex_lock(&lock);
		printf("\rshared integer's value = %i\n", shared_data);
//		pthread_mutex_unlock(&lock);
	}

	printf("\n");

	pthread_join(thread_ID, &exit_status);
	pthread_mutex_destroy(&lock);
	return 0;
}
