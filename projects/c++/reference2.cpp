#include <iostream>

int main() 
{
using std::cout; 
using std::endl;

int myAge = 18;
int &rMyAge = myAge;

myAge = 20;

cout << "value of myAge: " << myAge << endl;
cout << "value of myAge reference: " << rMyAge << endl;

int yourAge = 0;
cout << "Enter your age: ";
std::cin >> yourAge;

rMyAge = yourAge;

cout << "value of myAge: " << myAge << endl;
cout << "value of myAge reference: " << rMyAge << endl;
cout << "value of yourAge: " << yourAge << endl;
return 0;
}

