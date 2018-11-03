#include <stdio.h>
#include <stdlib.h>

struct object
{
    int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q;
};

struct foo
{
    struct object *o;
    int f,g,h;
};

int main()
{
    printf("%lu\n", sizeof(struct foo));
    return 0;
}
