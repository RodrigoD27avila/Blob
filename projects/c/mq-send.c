#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <unistd.h>

#define QUEUE "/my_queue"

int main(int argc, char **argv)
{
	mqd_t queue;
	int msg;

	if ((queue = mq_open(QUEUE, O_RDWR)) < 0) {
		perror("mq_open");
		exit(EXIT_FAILURE);
	}

	for (;;) {
		msg = random() % 100;
		if ((mq_send(queue, (void *)&msg, sizeof(msg), 0)) < 0) {
			perror("mq_send");
			exit(EXIT_FAILURE);
		}
	}

	printf("send a message with value %i\n", msg);
	sleep(1);

	return 0;
}
