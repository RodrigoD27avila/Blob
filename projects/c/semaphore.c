#include <semaphore.h>

int   shared;
sem_t binary_sem;

void *thread_func(void *arg)
{
	sem_wait(&binary_sem);
	sem_signal(&binary_sem);
}

int main()
{
	sem_init(&binary_sem, 1);
	
	sem_wait(&binary_sem);
	sem_segnal(&binary_sem);

	sem_destory(&binary_sem);
	return 0;
}
