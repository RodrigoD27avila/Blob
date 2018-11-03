#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int x = 0;

	fork();
	x++;
	sleep(5);
	wait(0);

	fork();
	wait(0);
	sleep(5);
	x++;

	printf("x = %i\n", x);
	return 0;
}
