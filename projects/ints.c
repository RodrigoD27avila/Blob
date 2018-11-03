#include <stdio.h>
#include <time.h>

int main()
{
	unsigned long long int i64 = 0xffffffffffffffff;
	printf("64bit = %lu\n", i64);
	printf("32bit = %lu\n", (i64 >> 32));

	printf("32bit cast = %u\n", (unsigned int)(i64 >> 32));
	printf("sizeof clock_t = %lu\n", sizeof(clock_t));
	printf("sizeof int32   = %lu\n", sizeof(int));
	printf("sizeof int64   = %lu\n", sizeof(long long));

	return 0;
}
