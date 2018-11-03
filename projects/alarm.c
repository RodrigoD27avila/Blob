#include <stdio.h>
#include <unistd.h>

int main()
{
	alarm(10);
	pause();
	printf("Good Bye!\n");
	return 0;
}
