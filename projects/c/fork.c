#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	int   rv;

	if ((pid = fork()) == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) { /*Child*/
		printf("CHILD: This is the child process.\n");
		printf("CHILD: My PID is %d.\n", getpid());
		printf("CHILD: My parent PID is %d.\n", getppid());
		printf("CHILD: Enter my exit status:\n");
		scanf("%d", &rv);
		printf("CHILD: I'm outta of here!\n");
		exit(rv);
	}
	else { /*Parent*/
		printf("PARENT: This is the parent process.\n");
		printf("PARENT: My PID is %d.\n", getpid());
		printf("PARENT: My child's PID is %d.\n", pid);
		printf("PARENT: I'm now waiting for my child to exit()...\n");
		wait(&rv);
		printf("PARENT: My child's exit status is %d.\n",
			WEXITSTATUS(rv));
		printf("PARENT: I'm outta of here!\n");
	}

	return 0;
}
