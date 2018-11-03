#include <iostream>
#include <vector>

using namespace std;

int
main (void) {
	
	vector <int> v;
	int data;

	do {

		cout << "Entre com o dado (" << v.size () << "): ";
		cin >> data;
		cin.get ();
		if (cin.good ()) {
			v.push_back (data);
		}

	} while (cin.good ());

	cout << endl << "O primeiro elemento é " << v.front () << endl;
	cout << "O ultimo elemento é " << v.back () << endl;

	for (int i = 0; i < (int) v.size (); i++) {
		cout << "v[" << i << "] = " << v[i] << endl;
	}

	cout << (v.empty () ?"O vetor está vazio!" : "O vetor não está vazio!") << endl;
	v.clear ();
	cout << (v.empty () ? "O vetor está vazio!" : "O vetor não está vazio!") << endl;
	cin.get ();
	return 0;
}
