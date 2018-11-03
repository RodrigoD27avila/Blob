#include <stdio.h>
#include <stdlib.h>

#define MAX_STARS 32000

static int t[MAX_STARS];
static int total[15000];

void add(int i, int val)
{
	t[i] += val;
}

int sum(int i)
{
	int res = 0;
	int j;
	for (j=0; j<=i; j++) {
		res += t[j];
	}
	return res;
}


int main()
{
	int x, y;

	int size;
	int i;
	scanf("%d", &size);
	for (i=0; i<size; i++) {
		scanf("%d %d", &x, &y);
		add(x, 1);
		total[sum(x)-1] += 1;
	}


	for (i=0; i<size; i++) {
		printf("%i\n", total[i]);
	}

	return 0;
}
