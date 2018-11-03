#include <iostream>

static int const kWidth = 200;

namespace {
static int const kWidth = 1000;
}

int main()
{
	std::cout << ::kWidth << std::endl;
}
