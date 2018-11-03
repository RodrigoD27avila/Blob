#include <stdio.h>

struct foo
{
    union u
    {
     unsigned int a:1, b:1, c:1, d:1, e:1, f:1, g:1, h:1;
    } u;
};

int main()
{
    struct foo f;
    f.u.a = 0;
    f.u.b = 1;
    f.u.c = 1;
    f.u.d = 1;
    f.u.e = 0;
    f.u.f = 0;
    f.u.g = 1;
    f.u.h = 0;

    int *c = (int*)&f;
    printf("%i\n", *c);
    return 0;
}
