#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __NNTREE{
	struct __NNTREE *children[256];
} NNTREE;


NNTREE *nntree_new()
{
	NNTREE *nntree = malloc(sizeof(NNTREE));
	if (nntree == NULL) {
		fprintf(stderr, "Unable to create a nntree.\n");
		exit(EXIT_FAILURE);
	}
	memset(nntree, 0, sizeof(NNTREE));
	return nntree;

};

void create_nodes(NNTREE *nn)
{
	int i;
	for (i=0; i<256; i++) {
		nn->children[i] = nntree_new();
	}
}

void delete_nodes(NNTREE *nn)
{
	int i;
	for (i=0; i<256; i++) {
		free(nn->children[i]);
	}
}

int main()
{
	NNTREE *nn =  nntree_new();
	int i;
	for (i=0; i<256; i++) {
		nn->children[i] = nntree_new();
		create_nodes(nn->children[i]);
	}
	for (i=0; i<256; i++) {
		delete_nodes(nn->children[i]);
		free(nn->children[i]);
	}
	free(nn);
}
