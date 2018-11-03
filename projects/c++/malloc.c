#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    printf("%u\n", sizeof(int*));
    int *a = malloc(sizeof(int*));
    free(a);
    a = NULL;
    return 0;
}
