#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    ostringstream o(ostringstream::out);
    o << 200;
    cout << o.str();
    return 0;
}
