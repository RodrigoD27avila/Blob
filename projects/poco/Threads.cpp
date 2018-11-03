#include <Poco/Runnable.h>
#include <Poco/Thread.h>

#include <iostream>

using namespace Poco;
using namespace std;


class MyWorker : public Runnable
{
public:
    MyWorker(int k=-1) : Runnable(), n(k) {}

    void run()
    {
        for(int i=0; i < 10; ++i)
        {
            cout << n << endl;
        }
    }

private:
    int n;
};

int main()
{
    const int N = 5;
    int i;

    MyWorker w[N];
    for(i=0; i < N; ++i) w[i] = MyWorker(i);

    Thread t[N];
    for (i=0; i < N; ++i) t[i].start(w[i]);
    for (i=0; i < N; ++i) t[i].join();

    cout << endl << "Threads joined" << endl;

    return 0;
}
