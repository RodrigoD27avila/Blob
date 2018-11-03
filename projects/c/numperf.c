#include <stdio.h>
int main () {
	long long unsigned int NUM[5]= {6, 28, 496, 8128, 33550336}, i = 0, j = 0;
	for(i = 0; i < 5; i++){
		printf ("1 ");
		for(j = 2; j<= (NUM[i] / 2); j++){
			if ((NUM[i] % j) == 0){
				printf ("%llu ", j);
			}
		}
	printf ("\n%llu é perfeito!!\n", NUM[i]);
	}
	return 0;
}
