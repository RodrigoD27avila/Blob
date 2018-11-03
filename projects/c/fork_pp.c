#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;

	if ((pid = fork()) == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) { /*Child*/
		while (1) {
			fprintf(stdout, "I'm running...\n");
			fflush(stdout);
			sleep(1);
		}
		printf("CHILD: I'm outta of here!\n");
	}
	else { /*Parent*/
		printf("PARENT: I'm outta of here!\n");
		printf("PARENT: My child's PID is %d\n", pid);
	}

	return 0;
}
