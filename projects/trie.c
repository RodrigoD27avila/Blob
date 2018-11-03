#include <stdio.h>
#include <stdlib.h>

typedef struct __TRIE {
    struct __TRIE *children[256];
    void  *base;
    int   size;
} TRIE;

int main()
{

}
