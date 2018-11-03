#include <stdio.h>

struct foo
{
//	unsigned int fuu[0];	
};

int main()
{
	printf("%u\n", sizeof(struct foo));
	return 0;
}
