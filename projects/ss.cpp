#include <iostream>
using namespace std;

class SS {
public:
	virtual void doit() = 0;
};

class FF : public SS {
public:
	FF();
	virtual ~FF();
	void doit();
};

FF::FF()
{
	cout << "init FF" << endl;
}

FF::~FF()
{
	cout << "FF quit" << endl;
}
void FF::doit()
{
	cout << "FF doit" << endl;
}

class GG {
public:
	FF a;
	FF b;
	FF c;
	FF d;
	FF e;
};

int main()
{
	FF f;
	f.doit();

	GG g;
}
