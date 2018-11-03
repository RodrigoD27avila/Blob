#include <stdio.h>
#define MIN(x, y) (x < y ? x : y)

int main(int argc, char *argv[]) {
	int x = 1;
	int y = 2;
	x >>= 2;
	printf("%i x = %i y=%i", MIN(x, y), x, y);
	return 0;
}
