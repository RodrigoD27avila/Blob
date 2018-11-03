#include <queue>
using namespace std;

int main()
{
    queue<unsigned int> q;
    unsigned int i;

    for (i=0; i<10000000; ++i)
    {
        q.push(i);
    }
    return 0;
}
