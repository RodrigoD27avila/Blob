#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int i = 567;
	ofstream f;
	f.open("teste.int", ios::binary);
	f.write((char *)&i, sizeof(int));
	f.flush();
	f.close();

	int j;
	ifstream g;
	g.open("teste.int", ios::binary);
	g.read((char *)&j, sizeof(int));
	g.close();

	cout << j << endl;
	
	return 0;
}
