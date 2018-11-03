#include <iostream>




auto foo (auto k)
{
	std::cout << k << std::endl;
	return 1;

}

void foo (std::string& k)
{
	std::cout << "string" << std::endl;
	std::cout << k << std::endl;
}

void bar() {
}

int main()
{
	std::string a = "Kakaroto";
	int i = foo(10);
	int j = foo(a);
	int k = bar();

	std::cout << i <<":"<< j <<":"<< k << std::endl;
}
