#include <iostream>
using namespace std;

void foo(const char *c)
{
    cout << c[0] << endl;
}

int main(int argc, char **argv)
{
    char nome[] = "Rodrigo\0";
    int i = 0;
    for (i=0; i < 7; ++i)
    {
        char *t = &nome[i];
        foo (t);
    }

    return 0;
}

