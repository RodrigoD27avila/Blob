#include <stdio.h>
#include <stdlib.h>

struct C_Node {
	struct _Node *next;
	int info;
};

struct C_List {
	struct C_Node *first;
};


struct C_Node *C_Node_New(int info)
{
	struct C_Node *node = malloc(sizeof(struct C_Node));
	node->next = NULL;
	node->info = info;

	return node;
}

struct C_List C_List_New()
{
	struct C_List *list = malloc(sizeof(struct C_List));
	list->first = NULL;
}

void push(struct C_List *list, int info)
{
	struct C_Node *newnode = C_Node_New(info);
	newnode->next  = list->first;
	list->first = newnode;

	struct C_Node node = newnode->next;
	while (node != NULL && node->next != newnode->next) {
		node = node->next;
	}

	if (node != NULL) {
		node->next = newnode;
	}
}
