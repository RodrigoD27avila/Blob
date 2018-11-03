#include <stdio.h>
#include <stdlib.h>

typedef int Sint;

static int compar(const void *v1, const void *v2)
{
        const Sint *r1 = (const Sint *)v1;
        const Sint *r2 = (const Sint *)v2;

        if ((*r1) > (*r2)) {
                return 1;
        }
        else if ((*r1) < (*r2)) {
                return -1;
        }

        return 0;
}

int main()
{
	Sint array[] = {9,8,7,6,5,4,3,2,1,0};
	qsort(array, 10, sizeof(Sint), compar);

	int i;
	for (i=0; i<10; i++) {
		printf("%i\n", array[i]);
	}
	return 0;
	
}
