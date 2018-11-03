#include <iostream>
#include <bitset>
using namespace std;

int main(int argc, char **argv)
{
    bitset<64> u;
    cout << u.to_ulong() << endl;
    cout << u.to_string() << endl;

    return 0;
}
