#include <stdio.h>

struct contador
{
    int value;
};

int main()
{
    struct contador c = {0};
    int i;

    for (i=0; i < 10; i++)
    {
        c.value += (c.value+1) + i;
    }

    printf("%i", c.value);

    return 0;
}
