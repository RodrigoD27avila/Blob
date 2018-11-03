#include <stdio.h>

static int t[15000];
static int total[15000];

void add(int i, int val)
{
	for (; i < 15000; i+= (i+1) & -(i+1))
		t[i] += val;
}

int sum(int i)
{
	int res = 0;
	for (; i>=0; i-= (i+1) & -(i+1))
		res += t[i];
	return res;
}

int main()
{
	int i;
	for (i=15000; i; i--) {
		add(i, 1);
		total[sum(i)-1] +=1;
	}

	for (i=0; i<15000; i++) {
		printf("%i\n", total[i]);
	}

	return 0;
}
