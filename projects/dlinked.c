#include <stdio.h>
#include <stdlib.h>

struct D_Node {
	struct D_Node *next;
	struct D_Node *prev;
	int data;
};

struct D_Linked {
	struct D_Node *first;
};

struct D_Node *D_Node_New(int data)
{
	struct D_Node *node = malloc(sizeof(struct D_Node));
	node->next = NULL;
	node->prev = NULL;
	node->data = data;

	return node;
}

struct D_Linked *D_Linked_New()
{
	struct D_Linked *list = malloc(sizeof(struct D_Linked));
	list->first = NULL;
	return list;
}

void D_Linked_Push(struct D_Linked *root, int data)
{
	struct D_Node *node  = D_Node_New(data);
	struct D_Node *first = root->first;

	node->next = first;

	if (first != NULL) {
		first->prev = node;
	}

	root->first = node;
}

struct D_Node *D_Linked_Pop(struct D_Linked *root)
{
	struct D_Node *node = root->first;
	// verifica se a lista está vazia
	if (node != NULL) {

		if (node->next != NULL) {
			node->next->prev  = node->prev;
		}

		if (node->prev != NULL) {
			node->prev->next  = node->next;
		}

		root->first = node->next;

		node->prev = NULL;
		node->next = NULL;
		return node;
	}

	return NULL;
}

struct D_Node *D_Linked_Remove(struct D_Linked *root, int value)
{
	struct D_Node *node = root->first;

	// procura pelo node com o valor
	while (node != NULL && node->data != value) {
		node = node->next;
	}

	if (node == NULL) {	// não achou nenhum valor
		return NULL;
	} else {

		if (node->next != NULL) {
			node->next->prev  = node->prev;
		}

		if (node->prev != NULL) {
			node->prev->next  = node->next;
		}

		if (root->first->data == value) {
			root->first = node->next;
		}

		node->prev = NULL;
		node->next = NULL;

		return node;
	}
}

void D_Linked_Print(struct D_Linked *root)
{
	struct D_Node *node = root->first;
	while (node != NULL) {
		printf("|  [%i[ <- (%i) -> ]%i] |",
		(node->prev != NULL) ? node->prev->data : -1,
		 node->data,
		(node->next != NULL) ? node->next->data : -1);
		node = node->next;
	}

	printf("\n");
}

void D_Linked_Destroy(struct D_Linked *root)
{
	struct D_Node *node = root->first;
	while (node != NULL) {
		struct D_Node *prev = node;
		node = node->next;
		free(prev);
	}

	free(root);
}

void D_Linked_Swap(struct D_Linked *root, struct D_Node *first, int val1, int val2,
	struct D_Node *found)
{
	struct D_Node *node = first;

	while (node != NULL &&
		(node->data != val1 && node->data != val2)) {
		node = node->next;
	}

	if (node != NULL) {
		if (found) {
			struct D_Node *node_next  = node->next;
			struct D_Node *node_prev  = node->prev;
			struct D_Node *found_next = found->next;
			struct D_Node *found_prev = found->prev;

			node->next  = found_next;
			node->prev  = found_prev;

			found->next = node_next;
			found->prev = node_prev;

			if (node_next != NULL) {
				node_next->prev = found;
			}

			node_prev->next = found;
			found_next->prev = node;

			if (found_prev != NULL) {
				found_prev->next = node;
			}

			if (found->data == root->first->data) {
				root->first = node;
			}

		} else {
			D_Linked_Swap(root, node->next, val1, val2, node);
		}
	}
}

int main()
{
	struct D_Linked *l = D_Linked_New();

	D_Linked_Push(l, 10);
	D_Linked_Push(l, 11);
	D_Linked_Push(l, 12);
	D_Linked_Push(l, 13);
	D_Linked_Push(l, 14);

	D_Linked_Print(l);
	D_Linked_Swap(l, l->first, 10, 14, NULL);
	D_Linked_Print(l);

	D_Linked_Destroy(l);
}
