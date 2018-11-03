#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct func_t
{
    int (*sum)(int a, int b);
} func = {0};

int sum(int a, int b)
{
    return a + b;
}

typedef int (*sum_t)(int, int);
sum_t ret()
{
    return sum;
}

int main()
{
    func.sum = sum;

    int sum(int a, int b)
    {
        return a + b;
    }

    printf("%i\n", sum(10, 10));
    printf("%i\n", func.sum(10, 10));
    printf("%i\n", ret()(10, 10));

    return 0;
}
