#include <list>
using namespace std;

int main()
{
	list<int> ll;
	for (int i=0; i<1000000; i++) {
		ll.push_back(i);
	}
}
