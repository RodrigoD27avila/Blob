#include <stdio.h>
#include <stdlib.h>

typedef struct __TREE {
    int info;
    struct __TREE *left;
    struct __TREE *right;
} TREE;


TREE *TREE_New(int info)
{
    TREE *t = malloc(sizeof(TREE));
    t->info   = info;
    t->left   = NULL;
    t->right  = NULL;
    return t;
}

void insert(TREE **root, int info, TREE *parent)
{
    TREE *p;
    if (*root == NULL) {
        p = TREE_New(parent, info);
        *root = p;
    } else {
        if (info < (*root)->info)
                insert(&((*root)->right), info, *root)
        else
            insert(&((*root)->left), info, *root)
    }
}

TREE *search(TREE *root, int info)
{
    if (root == NULL)       return NULL;
    if (root->info == info) return root;

    if (info < root->info) {
        return (search(root->left, info));
    } else {
        return (search(root->right, info));
    }
}

TREE *minimum(TREE *root)
{
    TREE  min;
    if (root == NULL) return NULL;

    min = root;
    while (min->left != NULL) {
        min = min->left;
    }
}
