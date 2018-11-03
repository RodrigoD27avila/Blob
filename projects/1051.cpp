#include <stdio.h>

int main()
{
	double salary, a=0.0f, b=0.0f, c=0.0f;
	scanf("%lf", &salary);

	if (salary > 2000.0f) {

		if (salary > 4500.0f) {
			c = salary - 4500.0f;
			b = 1500.0f;
			a = 1000.0f;
		}
		else if (salary > 3000.0f) {
			c = 0.0f;
			b = salary - 3000.0f;
			a = 1000.0f;
		}
		else if (salary > 2000.0f) {
			c = 0.0f;
			b = 0.0f;
			a = salary - 2000.0f;
		}
	}


	if (salary > 2000.0f) {
		printf("R$ %.2lf\n", (a*0.08)+(b*0.18)+(c*0.28));
	} else {
		printf("Isento\n");
	}
}
