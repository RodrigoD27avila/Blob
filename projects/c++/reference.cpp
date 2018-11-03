#include <iostream>

int main() 
{
using std::cout;
using std::endl;
int age = 18;
int &rAge = age; //reference

cout << "age: " << age << endl;
cout << "rAge: " << rAge << endl;

rAge = 20;

cout << "age: " << age << endl;
cout << "rAge: " << rAge << endl;

age = 24;

cout << "age: " << age << endl;
cout << "rAge: " << rAge << endl;
return 0;
}
