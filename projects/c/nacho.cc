#include <iostream>
#define MIN(x, y) (x < y ? x : y)

int main(void) {
	int x = 1;
	int y = 2;
	x >>= 2;
	std::cout << MIN(x, y) << " x=" << x << " y=" << y;
	return 0;
}
