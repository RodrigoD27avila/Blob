#include <stdlib.h>
#include <stdio.h>

struct object
{
    int a, b, c;
};

struct foo
{
    int d,e,f;
};

int main()
{
    void *p = malloc(sizeof(struct object) + sizeof(struct foo));

    struct object *o = p;
    o->a = 10;
    o->b = 10;
    o->c = 10;

    struct foo *f = p + sizeof(struct object);
    f->d = 20;
    f->e = 20;
    f->f = 20;

    int i = 0;
    for (i=0; i< 6; ++i)
    {
        int* ii = p;
        printf("%i\n", ii[i]);
    }

    return 0;
}
