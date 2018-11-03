#include <vector>
using namespace std;

template<class T>
class MyList : virtual public vector<T> {
	
};

int main()
{
	MyList<int> foo;
}
