#include <iostream>
#include <vector>

#include <signal.h>

using namespace std;

int main();

extern "C" void print_quit(int signal)
{
	cout << "Signal " << signal << endl;
}

int main()
{
	signal(SIGABRT, print_quit);
	signal(SIGINT, print_quit);
	signal(SIGTERM, print_quit);

	vector<int> v(10);
	v.at(100);
}
