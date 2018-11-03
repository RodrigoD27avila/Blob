#include <memory>


int main()
{
	auto a = std::make_shared<int>(12);
	return *a;
}
