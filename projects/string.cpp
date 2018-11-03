#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1 = "Rodrigo";
    string str2 = " D'avila";

    string str3;
    str3.append(str1);
    str3.append(str2);

    cout << str3 << endl;

    str2.assign("Fuu");

    cout << str2 << endl;
    cout << str3 << endl;
}
