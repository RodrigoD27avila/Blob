#include <stdio.h>
#include "teste_func.h"

void ggg(foo *f)
{
    bar b1 = create_bar();
    bar b2 = create_bar();
    bar b3;
    b3.a = 10;
    b3.b = 10;
    b3.c = 10;

    f->b1 = &b1;
    f->b2 = &b2;
    f->b3 = &b3;

}

int main()
{
    foo f = create_foo();
    ggg(&f);

    printf("%p\n", f.b1);
    printf("%p\n", f.b2);
    printf("%p\n", f.b3);

    return 0;
}
