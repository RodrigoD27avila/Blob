#include <stdlib.h>
#include <stdio.h>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    int (*add_ptr)(int, int) = add;
    printf("%i\n", add_ptr(10, 10));
    return 0;
}
