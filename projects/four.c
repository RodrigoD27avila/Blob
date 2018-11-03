#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long int U64;

typedef struct __NODE {
    struct __NODE *left;
    struct __NODE *right;
    U64 info;
} NODE;

NODE *NODE_New(U64 info)
{
    NODE *n  = malloc(sizeof(NODE));
    n->info  = info;
    n->left  = NULL;
    n->right = NULL;
    return n;
}

bool is_ordered(NODE *node)
{
}

NODE *NODE_rotate_left(NODE *n)
{
    NODE *root = n->right;
    n->right   = n->left;
    root->left = n;
    return root;
}

NODE *NODE_rotate_right(NODE *n)
{
    NODE *root  = n->left;
    n->left     = n->right;
    root->right = n;
    return root;
}
