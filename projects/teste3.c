#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i = 5;
    char *a = "Rodrigo";
    char *b = "D'avila";
    char buf[i + 10];

    strcpy(buf, a);
    memmove(b, buf + 7, 10);
    printf ("%s\n", buf);

    return 0;
}
