#include <stdio.h>
#include <math.h>

int main()
{
	long int i, j;
	for (i=0;i<10;i++) {
		for (j=0; j<100;j++) {
			printf("%.0lf\n", pow(j, i));
		}
	}
}
