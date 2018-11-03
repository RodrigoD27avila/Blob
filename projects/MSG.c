#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int a;
    short s[4];
} FOO;

typedef struct
{
    int a;
    short s[2];
} MSG;

int main()
{
    FOO f = {1, {1,2,3,4}};
    printf("%i, %i, %i, %i,\n", f.s[0], f.s[1], f.s[2], f.s[3]);

    MSG *mp, m = {4, {1, 0}};
    char *fp, *tp;

    mp = (MSG *) malloc(sizeof(MSG));
    for (fp = (char *)m.s, tp = (char *)mp->s; tp < (char *)(mp+1);)
        *tp++ = *fp++;

    printf("%s, %s\n", tp, fp);

    return 0;
}

