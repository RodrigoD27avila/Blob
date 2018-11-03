#include <stdio.h>

struct rgba32
{
	unsigned r:8;
	unsigned g:8;
	unsigned b:8;
	unsigned a:8;
};

struct rgba16
{
	unsigned r:4;
	unsigned g:4;
	unsigned b:4;
	unsigned a:4;
};

union colors
{
	unsigned      value;
	struct rgba32 color32;
	struct rgba16 color16;
};

int main()
{
	union colors colors = {0x01020304};
	struct rgba32 color1 = colors.color32;
	struct rgba16 color2 = colors.color16;
	
	printf("sizeof unsigned = %u\n", sizeof(unsigned));
	printf("sizeof rgba32   = %u\n", sizeof(struct rgba32));
	printf("sizeof rgba16   = %u\n", sizeof(struct rgba16));

	printf("r = %u\n", color2.r);
	printf("g = %u\n", color2.g);
	printf("b = %u\n", color2.b);
	printf("a = %u\n", color2.a);

	return 0;
}
