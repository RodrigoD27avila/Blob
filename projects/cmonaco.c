#include <stdio.h>

struct foo
{
    int a, b, c;
};

static void modify_foo(const struct foo *f)
{
    printf("%i, %i, %i\n", f->a, f->b, f->c);
}

int main(int argc, char **argv)
{
    static struct foo f = {10, 110, 1110};
    modify_foo(&f);

    auto i = 0;
    return 0;
}
