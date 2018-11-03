#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 64

static int buff[STR_LEN];

struct Node {
	unsigned int count;
	struct Node *children[256];
};

struct Node *node_new()
{
	struct Node *node = malloc(sizeof(struct Node));
	memset(node, 0, sizeof(struct Node));
	return node;
}

void show(struct Node *node, int pos)
{
	int i;
	for (i=0; i<256; i++) {
		if (node->children[i] == NULL) {
			continue;
		}

		buff[pos] = i;
		show(node->children[i], pos+1);
		buff[pos] = 0;

	}

	if (pos >= STR_LEN) {
		int j;
		for (j=0; j<STR_LEN; j++) {
			printf("%2x", buff[j]);
		}
		printf("\n%u\n", node->count);
	}
}

int main()
{
	FILE *file = fopen("Tibia.dat", "rb");
	if (!file) {
		exit(EXIT_FAILURE);
	}

	struct Node *tree = node_new();
	while (!feof(file)) {
		int i;
		struct Node *node = tree;
		for (i=0; i<STR_LEN && !feof(file);i++) {
			unsigned char c = 0;
			fread(&c, 1, 1, file);

			if (node->children[c] == NULL) {
				node->children[c] = node_new();
			}

			node = node->children[c];
		}

		node->count += 1;
	}

	fclose(file);

	show(tree, 0);
}
