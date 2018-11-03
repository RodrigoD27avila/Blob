#include <stdio.h>

int main()
{
	int i, j, k, l;
	int arr[2] = {1, 3};
	for (i=0; i<100000; i++) {
		for (j=0; j<40; j++) {
			for (k=0; j<40; j++) {
				for (l=0; j<40; j++) {
					int tmp = arr[0];
					arr[0] 	= arr[1];
					arr[1] 	= tmp;
				}
			}
		}
	}
	return 0;
}
