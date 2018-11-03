#include "mme.h"

int mme()
{
    printf("SIZE = %lu\n", 8 * sizeof(unsigned long int));
    unsigned long int *mm = malloc(3 * sizeof(unsigned long int));
    
    void *p1 = malloc(sizeof(int) * 10);
    void *p2 = malloc(sizeof(int) * 10);
    void *p3 = malloc(sizeof(int) * 10);

    printf("%p\n", p1);
    printf("%p\n", p2);
    printf("%p\n", p3);

    mm[0] = (unsigned long int)p1;
    mm[1] = (unsigned long int)p2;
    mm[2] = (unsigned long int)p3;

    printf("%lu\n", mm[0]);
    printf("%lu\n", mm[1]);
    printf("%lu\n", mm[2]);

    free((void *) mm[0]);
    free((void *) mm[1]);
    free((void *) mm[2]);
    return 0;
}
