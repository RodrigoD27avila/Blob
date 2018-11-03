#include <stdio.h>

struct foo
{
    int x;
};

void modify_foo(struct foo *f)
{
    f->x = 20;
}

int main()
{
    struct foo f;
    f.x = 10;

    printf("%i\n", f.x);

    modify_foo(&f);

    printf("%i\n", f.x);

    return 0;
}


