#include <iostream>
using namespace std;

class animal {
public:
	string name;
	int    count;
	virtual void breathe();
	virtual void run() = 0;

	animal(string name, int count);
};

class fish : public animal {
public:	
	fish() : animal("fish", 0) {}
	void breathe();
	void run();
};

class dog : public animal {
public:
	dog() : animal("dog", 0) {}
	void run();
};

animal::animal(string name, int count)
	: name (name),
	  count(count)
{}

void animal::breathe()
{
	cout << "The " << name <<" is breathing... " << endl;
}

void fish::breathe()
{
	cout << "The " << name <<" is bubling... " << endl;
}

void fish::run()
{
	cout << "The " << name <<" is swiming... " << endl;
}

void dog::run()
{
	cout << "The " << name <<" is running... " << endl;
}

int main()
{
	fish   fishobj;
	dog    dogobj;

	animal *ptr;

	ptr = &fishobj;
	ptr->breathe();
	ptr->run();

	ptr = &dogobj;
	ptr->breathe();
	ptr->run();

	
}
