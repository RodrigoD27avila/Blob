#include <stdio.h>

void __f()
{
    printf(">> f\n");
}

void f() __attribute__ ((weak, alias("__f")));

int main()
{
    f();
    return 0;
}

