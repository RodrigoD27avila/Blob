#include <iostream>

namespace losfoos {
class Foo {
protected:
	int a;
	int b;
};
}

namespace losboos {
class Boo {
protected:
	int a;
	int b;
};
}

namespace losbars {
class Bar : public losfoos::Foo, public losboos::Boo {
public:
	Bar() {losfoos::Foo::a = 10;}
};
}

int main()
{
	losbars::Bar b;
	std::cout << b.Foo.a << std::endl;

}
