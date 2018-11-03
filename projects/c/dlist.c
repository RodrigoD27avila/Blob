#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct List List;
struct List {
	List *back;
	List *next;
	void *data;
};

void list_add(List *list, void *data)
{
	List *new = malloc(sizeof(List));
	new->next  = list->next;
	new->back  = list;

	if (!list->back) {
		list->back = new;
	}

	list->next = new;
}

List *list_pop(List *list)
{
	List *next = list->next, *current;
	if (!next) goto not_have_next;

	current = next;
	next    = next->next;

	list->next = next;
	if (next) next->back = list;

	return current;

not_have_next:
	return NULL;		
}

int main()
{
	static List l;
	int i;
	for (i=0; i < 20000000; i++) {
		list_add(&l, NULL);
	}

	sleep(10);	
	List *r = NULL;
	do {
//		printf("%p\n", r);
		free(r);
		r = list_pop(&l);
	} while (r);

	return 0;
}
