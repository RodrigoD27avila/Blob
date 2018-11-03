#include <stdio.h>
#include <stdlib.h>

struct __NODE {
    struct __NODE *next;
    int info;
} NODE;

void insertP(int info);
void insertI(int info);

typedef void (*insert_func)(int);

NODE *node[2];

static insert_func funcs[2] = {
    insertP, insertI,
};

void insert(int info, insert_func func)
{ func(info); }


NODE *NODE_New(int info)
{
    NODE *n = malloc(sizeof(NODE));
    n->info = info;
    n->next = NULL;
    return n;
}

int main()
{
    int n, i, nn;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &nn);
        int h = (nn & 0x1);
    }
}
