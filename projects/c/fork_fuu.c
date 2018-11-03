#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

struct fuu {
	int a;
};

int main()
{
	pid_t pid;
	struct fuu *fuu = malloc(sizeof(struct fuu));
	fuu->a = 0;

	if ((pid = fork()) == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) { /*Child*/
		while (1) {
			fuu->a += 1;
			fprintf(stdout, "CHILD: %i\n", fuu->a);
			sleep(2);
		}
	
	}

	else { /*Parent*/
		while (1) {
			fuu->a += 1;
			fprintf(stdout, "PARENT: %i\n", fuu->a);
			sleep(1);
		}
	}

	return 0;
}
