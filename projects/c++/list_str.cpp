#include <iostream>
#include <sstream>
#include <string>
#include <list>
using namespace std;

int main(int argc, char **argv)
{
    int it = 90000;
    ostringstream sr;
    string s;
    const char *carr;

    sr << it;
    s = sr.str();
    carr = s.c_str();

    list<char> l;

    int i;
    for(i=0; (carr[i]) != 0; ++i)
    {
        l.push_back(carr[i]);
    }

    cout << l.front() << endl;
    return 0;
}
