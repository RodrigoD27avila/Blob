#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc <= 1)
        return -1;

    unsigned long long int i;
    unsigned long long int n = atoi(argv[1]);

    for (i=1; i < n; i++)
    {
        if ((n % i) == 0)
            printf("%Lu x %Lu\n", i, n/i);
    }

    return 0;
}
