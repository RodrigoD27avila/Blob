#include <stdio.h>

typedef int (*foo_t)(int, int);

int soma(int a, int b)
{
    return a + b;
}

int subtrai(int a, int b)
{
    return a - b;
}

foo_t call_func(int i)
{
    if (i > 0)
        return soma;

    return subtrai;
}


int main ()
{
    foo_t foo;
    foo = call_func(1);
    printf("%i\n", foo(10, 10));
    return 0;
}
