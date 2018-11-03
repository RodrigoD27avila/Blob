#include <stdio.h>
#include <stdlib.h>

typedef struct _bar bar;
struct _bar
{
    void *data;
};

typedef struct _foo foo;
struct _foo
{
    int a;
    bar *data;
};

int main()
{
    foo **f = malloc(10*sizeof(foo*));
    f[0] = malloc(sizeof(foo));
    f[1] = malloc(sizeof(foo));
    f[2] = malloc(sizeof(foo));

    ((foo*)f[0])->data = malloc(sizeof(bar));
    f[1]->data = malloc(sizeof(bar));
    f[2]->data = malloc(sizeof(bar));

    free(f[0]->data);
    free(f[1]->data);
    free(f[2]->data);

    free(f[0]);
    free(f[1]);
    free(f[2]);
    free(f);

    foo *f2 = malloc(sizeof(foo));
    f2->data = malloc(sizeof(bar));
    f2->data->data = malloc(sizeof(int)*10);

    foo *f3 = realloc(f2, sizeof(foo) * 2);
    f3[1].data = malloc(sizeof(bar));
    f3[1].data->data = malloc(sizeof(int)*10);


    char *c = (char*)malloc(sizeof(char) * 8);

    c[0] = 'R';
    c[1] = 'o';
    c[2] = 'd';
    c[3] = 'r';
    c[4] = 'i';
    c[5] = 'g';
    c[6] = 'o';

    free(c);

    char *c2 = "Rodrigo";
    printf("%s\n", c2);

    foo f4 = {0 ,NULL};
    f4.a = 0;
    f4.data = malloc(sizeof(bar));
    f4.data->data = NULL;//malloc(sizeof(int)*10);

    foo *f5 = realloc(f3, sizeof(foo) * 3);
    f5[2] = f4;

    free(f5[2].data->data);
    free(f5[1].data->data);
    free(f5[0].data->data);
    free(f5[2].data);
    free(f5[1].data);
    free(f5[0].data);
    free(f5);
    return 0;
}

