#include <stdio.h>

struct registers_t {
	/* r1 */
	union {
	unsigned int r1;
	struct {
		unsigned short l1;
		unsigned short h1;
	};
	};
	/* r2 */
	union {
	unsigned int r2;
	struct {
		unsigned short l2;
		unsigned short h2;
	};
	};
};

int main (int argc, char **argv)
{
	static struct registers_t reg = {
		.r1 = 65536,
		.r2 = 65537,
	};
	printf("r1 lower %u\n", reg.l1);
	printf("r1 hight %u\n", reg.h1);
	printf("r2 lower %u\n", reg.l2);
	printf("r2 hight %u\n", reg.h2);
	printf("r1 lower address %lu\n", (size_t)(&reg.l1));
	printf("r1 hight address %lu\n", (size_t)(&reg.h1));
	printf("r2 lower address %lu\n", (size_t)(&reg.l2));
	printf("r2 hight address %lu\n", (size_t)(&reg.h2));
	return 0;	
}

