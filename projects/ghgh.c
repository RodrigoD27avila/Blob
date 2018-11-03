#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int a,b,c;
} foo;

int main()
{
    foo *myfoos[32];
    memset(myfoos, 0, 32*sizeof(foo*));

    myfoos[0] = (foo*) malloc(sizeof(foo));
    myfoos[0]->a = 10;
    myfoos[0]->b = 11;
    myfoos[0]->c = 12;

    if (!myfoos[1])
        printf("IS NULL\n");

    printf("%i\n", myfoos[0]->a);
    printf("%i\n", myfoos[0]->b);
    printf("%i\n", myfoos[0]->c);
    return 0;
}
