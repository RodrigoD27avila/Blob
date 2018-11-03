#include <assert.h>

double x () {
	double j = 0.0;
	for (double i=2.0; i<1000000000.0; i+=1.0) {
		j=i;
		for (double k=3; k <= 5; k++) {
			j = k;
		}
	}

	return j;
}

int main()
{
	double y = x();
	assert(y == 5.0);
}
