#include <stdio.h>
#include <math.h>

#define DIMENSION 3

typedef int point[DIMENSION];

double distance(point a, point b)
{
	int i;
	double d = 0.0f;
	for (i=0; i< DIMENSION; i++) {
		d += (a[i]-b[i]) * (a[i]-b[i]);
	}

	return (sqrt(d));

}

int main()
{
	int i;
	point p1 = {10, 10, 10};
	point p2 = {20, 20, 20};

	printf("%f\n", distance(p1, p2));

	return 0;



}
