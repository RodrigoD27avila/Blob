#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_func(void *arg)
{
	int i = 0;
	while (i < 10) {
		usleep(1000 * (random() % 1000));
		printf("thread_func says: %i\n", (int)arg);
		++i;
	}

	return NULL;
}

int main()
{
	pthread_t pth[100];
	int i;

	

	for (i=0; i < 100; i++) {
		pthread_create(&pth[i], NULL, thread_func, (void*)i);
	}
	
	for (i=0; i < 100; i++) {
		pthread_join(pth[i], NULL);
		printf("\n>>>>||||<<<<\n");
	}
	
	i=0;
	while (i < 10) {
		usleep(1000 * 100);
		printf("main() is Running...\n");
		++i;
	}

	return 0;
}
