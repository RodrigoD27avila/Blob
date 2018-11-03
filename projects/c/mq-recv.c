#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <sys/stat.h>

#define QUEUE "/my_queue"

/*COMMENT*/

int main(int argc, char **argv)
{
	mqd_t queue;
	struct mq_attr attr;
	int msg;

	attr.mq_maxmsg  = 10;
	attr.mq_msgsize = sizeof(msg);
	attr.mq_flags   = 0;

	umask(0);

	if ((queue = mq_open(QUEUE, O_RDWR | O_CREAT, 0666, &attr)) < 0) {
		perror("mq_open");
		exit(EXIT_FAILURE);
	}

	for (;;) {
		if ((mq_receive(queue, (void *)&msg, sizeof(msg), 0)) < 0) {
			perror("mq_receive");
			exit(EXIT_FAILURE);
		}
	}

	printf("received msg value %i\n", msg);

	return 0;
}
