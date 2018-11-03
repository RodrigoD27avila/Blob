#include <stdio.h>
#include <stdlib.h>

typedef struct Tree Tree;
struct Tree {
	Tree *node0;
	Tree *node1;
};

Tree *tree_new_node(Tree *tree, int node)
{
	Tree *new =  malloc(sizeof(Tree));

	Tree **current = (Tree **)tree;
	current[node]  = new;

	return new;
}

int main()
{
	static Tree tree;

	Tree *new;

	new = tree_new_node(&tree, 0);
	tree_new_node(new, 1);
	new = tree_new_node(&tree, 1); 

	free(tree.node0->node1);	
	free(tree.node0);	
	free(tree.node1);	

	return 0;
}
