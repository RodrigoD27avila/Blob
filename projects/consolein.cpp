#include <iostream>
using namespace std;


int main()
{
	string str;

	cout << "Qual é o seu nome?" << endl;
	getline(cin, str);
	cout << "Seu nome é " << str << endl;

	return 0;
}
