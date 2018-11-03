#include <stdlib.h>

typedef struct _bar bar;
struct _bar
{
    int a, b, c;
};

typedef struct _foo foo;
struct _foo
{
    bar *b1, *b2, *b3;
};

foo create_foo();
bar create_bar();

