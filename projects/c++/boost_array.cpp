#include <boost/array.hpp>
using namespace boost;

int main()
{
    const unsigned int size = 100000000;
    array<unsigned int, size> *a = new array<unsigned int, size>();
    unsigned int i;

    for(i=0; i<size; ++i)
    {
        a->at(i)= i;
    }

    delete a;

    return 0;
}
