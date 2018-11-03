#include <stdio.h>

struct foo
{
    struct {
    int a;
    int b;
    int c;
    } * bar;
};

struct foo *newfoo()
{
    struct foo f;
    f.bar = NULL;
    return &f;
}


int main()
{
    struct foo *f = newfoo();
    f->bar->a = 10;
    f->bar->b = 10;
    f->bar->c = 10;

    printf("%i\n", f->bar->a);
    printf("%i\n", f->bar->b);
    printf("%i\n", f->bar->c);

    return 0;
}
