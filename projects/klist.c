#include <stdio.h>
#include <stdlib.h>

struct K_node {
	struct K_node *next;
	int    data;
};

struct K_list {
	struct K_node *head;
};


struct K_list *k_list_new()
{
	struct K_list *l = malloc(sizeof(struct K_list));
	l->head = NULL;
	return l;
}

struct K_node *k_node_new()
{
	struct K_node *n = malloc(sizeof(struct K_node));
	n->next = NULL;
	n->data = 0;
	return n;
}

void k_list_add(struct K_list *l, int data)
{
	struct K_node *n = k_node_new();
	n->data = data;
	n->next = l->head;
	l->head = n;
}

struct K_node *k_list_get(struct K_list *l, int data)
{
	struct K_node *n = l->head;
	while (n != NULL && n->data != data) {
		n = n->next;
	}

	if (n == NULL)
		return NULL;


	return n;

}

void k_list_remove(struct K_list *l, int data)
{
	struct K_node *prev = NULL, *curr = l->head;
	while (curr != NULL && curr->data != data) {
		prev = curr;
		curr = curr->next;
	}

	if (curr == NULL) {
		return;
	}

	if (prev == NULL)  {
		l->head = curr->next;
	} else {
		prev->next = curr->next;
	}
}

bool k_list_empty(struct K_list *l)
{
	return (l->head == NULL);
}
void k_list_destroy(struct K_list *l)
{
	struct K_node *n = l->head, *t;
	while (n != NULL) {
		t = n;
		n = n->next;
		free(t);
	}

	free(l);
}

int main()
{
	struct K_list *l = k_list_new();
	int i;
	for (i=0;i <100000; i++) {
		k_list_add(l,i);
		k_list_remove(l, i);
	}

	k_list_destroy(l);
}
