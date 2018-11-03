#include <stdio.h>
#include <unistd.h>

int main()
{
	for (;;) {
		fprintf(stdout, ".");
		fflush(stdout);
		sleep(1);
	}
}

