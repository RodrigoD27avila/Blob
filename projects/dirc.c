#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	for (i=0; i<360; i+=6) {
		double rad = (i)*(3.14159/180);
		printf("{%.10f, %.10f},\n",
			cos(rad), sin(rad)*-1);
	}

	return 0;
}
