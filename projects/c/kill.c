#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <signal.h>

int main(int argc, char **argv)
{
	int ret;
	ret = kill(atoi(argv[1]),SIGKILL);
	return 0;
}
