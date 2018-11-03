#include <stdio.h>
#include <stdlib.h>
struct bar
{
    int a;
};

struct foo
{
    struct bar *b1;
    struct bar *b2;
    int i;
};

int main()
{
    struct bar *b = (struct bar *)calloc(1, sizeof(struct bar));
    struct foo *f = (struct foo *)calloc(1, sizeof(struct foo));

    f->b1 = b;
    f->b2 = b;

    printf("%p\n", f->b1);
    printf("%p\n", f->b2);

    free(f->b1);

    printf("%p\n", f->b1);
    printf("%p\n", f->b2);

    free(f->b2);
    free(f);
    return 0;
}
