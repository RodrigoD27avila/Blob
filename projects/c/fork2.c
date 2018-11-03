#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,  char **argv, char **envp)
{
	pid_t pid;
	pid = fork();

	if (pid < 0) {
		perror("Error fork():");
		exit(EXIT_FAILURE);
	}

	if(pid > 0) {
		wait(0);
	}
	else {
		execve("/bin/date", argv, envp);
		perror("Error execve():");
	}

	printf("Bye!\n");
	exit(EXIT_SUCCESS);
}
