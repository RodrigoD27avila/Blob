#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc <= 1)
        return -1;

    FILE *f = fopen(argv[1], "rb");

    if (!f)
        return -1;

    int c;
    do
    {
        c = fgetc(f);
        printf ("%x\n",c);
    }
    while (c != EOF);

    fclose(f);

    return 0;
}

