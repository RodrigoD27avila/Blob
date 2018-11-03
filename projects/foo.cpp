#include <iostream>

class Foo {
public:
	virtual auto calc(int x, int y) -> decltype(x*y) final {
		return x * y;
	}
};

int main()
{
	Foo f;
	std::cout << f.calc(100, 90) <<  std::endl;
	
}
