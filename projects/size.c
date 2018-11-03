#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%lu\n", sizeof(void*));
    printf("%lu\n", sizeof(size_t));


    char *c = malloc(10 *sizeof(char));
    printf("%lu\n", sizeof(c[0]));
    printf("%lu\n", sizeof(c[1]));

    printf("%lu\n", sizeof(*(c+1)));
    printf("%lu\n", sizeof((c+1)));
    return 0;
}
