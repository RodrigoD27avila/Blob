#include <pthread.h>

void *thread_function(void *arg)
{
	int *incomming = (int *)arg;
	return NULL;
}

int main()
{
	pthread_t thread_ID;
	void      *exit_status;
	int       value;

	value = 42;

	pthread_create(&thread_ID, NULL, thread_function, &value);
	pthread_join(thread_ID, &exit_status);
	return 0;
}
