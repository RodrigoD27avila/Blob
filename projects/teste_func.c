#include "teste_func.h"

foo create_foo()
{
    foo f;
    return f;
}

bar create_bar()
{
    return bbar();
}

static bar bbar()
{
    bar b;
    b.a = 0;
    b.b = 0;
    b.c = 0;
    return b;
}
