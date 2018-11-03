#include <stdio.h>
#include <stdlib.h>

typedef struct Lifo Lifo;
struct Lifo {
	Lifo *next;
	void *data;
};

void lifo_add(Lifo *lifo, void *data)
{
	Lifo *new  = malloc(sizeof(Lifo));
	new->next  = lifo->next;
	new->data  = data;
	lifo->next = new;
}

Lifo *lifo_pop(Lifo *lifo)
{
	Lifo *next = lifo->next, *current;
	if (!next) goto not_have_next;

	current = next;
	next    = next->next;

	lifo->next = next;
	return current;

not_have_next:
	return NULL;
}


int main()
{
	static Lifo q;

	int i;
	for (i=0; i<60000; i++) {
		lifo_add(&q, (void*)i);
	}

	for (i=0; i<60000; i++) {
		
		Lifo *r = lifo_pop(&q);
//		printf("%i: %i\n", i, (int)r->data);
//		free(r->data);
		free(r);
	}
	
	return 0;
}
