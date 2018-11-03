#include <stdio.h>
#include <stdlib.h>

#define MAX_STARS 32001

static int t[MAX_STARS];
static int total[15000];

void add(int i, int val)
{
        for (; i < MAX_STARS; i+= (i+1) & -(i+1))
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
