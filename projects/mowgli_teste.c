#include <mowgli.h>

int main()
{
    mowgli_init();
    mowgli_list_t l = {NULL, NULL, 0};
    int i;

    for (i = 0; i< 10000000; ++i)
    {
        mowgli_node_add("foo", mowgli_node_create(), &l);
    }
    return 0;
}
