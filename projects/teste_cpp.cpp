#include <vector>
using namespace std;

int main()
{
	vector<int> array;

	int i;
	for (i=0; i<1000000; i++) {
		array.push_back(i);
	}

}
