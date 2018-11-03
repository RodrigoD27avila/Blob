#include <stdio.h>

inline int sum(int a, int b)
{
	return a+b;
}

inline int minus(int a, int b)
{
	return a-b;
}


typedef int (*func_t)(int, int);

func_t funcs[] = {
	sum, minus,
};

int main()
{
	int i;
	for (i=0; i<2; i++) {
		printf("%i\n", funcs[i](10, 5));
	}
}
