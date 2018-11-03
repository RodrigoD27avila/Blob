#include <stdio.h>

#define QUEUESIZE 100

typedef struct {
	int q[QUEUESIZE+1];
	int first;
	int last;
	int count;
} queue;

void init_queue(queue *q)
{
	q->first = 0;
	q->last  = QUEUESIZE-1;
	q->count = 0;
}

void enqueue(queue *q, int x)
{
	q->last = (q->last+1) % QUEUESIZE;
	q->q[q->last] = x;
	q->count = q->count +1;
}

int dequeue(queue *q)
{
	int x = q->q[q->first];
	q->first = (q->first+1) % QUEUESIZE;
	q->count = q->count -1;
	return x;

}

int main()
{
	queue q;
	init_queue(&q);

	enqueue(&q, 10);
	enqueue(&q, 11);
	enqueue(&q, 12);

	printf("%i\n", dequeue(&q));
	printf("%i\n", dequeue(&q));
	printf("%i\n", dequeue(&q));
}
