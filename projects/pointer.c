#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *stack[2];

int main()
{
    unsigned  n1 = 123;
    unsigned  n2 = 123;

    stack[0] = n1;
    stack[1] = n2;

    printf("%p\n", &n1);
    printf("%p\n", &n2);

    return 0; 
}
