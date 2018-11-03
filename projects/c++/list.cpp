#include <list>
using namespace std;

int main(int argc, char **argv)
{
    list<unsigned int> *l = new list<unsigned int>();
    unsigned int *p;
    unsigned int size = 100000000;
    unsigned int i;

    p = l->get_allocator().allocate(size);

    for(i=0; i<size; ++i)
    {
        p[i] = i;
    }

    delete p;
    delete l;
    return 0;
}
