#include <stdio.h>
#include <stdlib.h>

typedef struct Fifo Fifo;
struct Fifo {
	Fifo *next;
	void *data;
};

void fifo_add(Fifo *fifo, void *data)
{
	Fifo *new = malloc(sizeof(Fifo));
	new->data = data;
	
	Fifo *next = fifo->next, *current = fifo;
	while (next) {
		current = next;
		next    = next->next;
	}

	current->next = new;
}

Fifo *fifo_pop(Fifo *fifo)
{
	Fifo *next = fifo->next, *current;
	if (!next)  goto not_have_next;

	current = next;
	next    = next->next;	

	fifo->next = next;
	return current;

not_have_next:
	return NULL;
}

int main()
{
	static Fifo f;
	int i;

	for (i=0; i<60000; i++) {
		fifo_add(&f, (void *)i);
	}
	
	for (i=0; i<60000; i++) {
		Fifo *r = fifo_pop(&f);
//		printf("%i: %i\n", i, (int)r->data);
//		free(r->data);
		free(r);
	}
	
	return 0;
}
