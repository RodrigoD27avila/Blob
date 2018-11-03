#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    if (cout.good())
    {
        cout.width(50);
        cout << "Hello " << 10 << '_' << 12.32 << endl;
    }

    return 0;
}
