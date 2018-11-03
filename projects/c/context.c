#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>

#define STACK_SIZE 500

ucontext_t cping, cpong, cmain;

void ping(void *args)
{
	int i;
	printf("%s iniciado.\n", (char *) args);
	for (i=0; i<4; i++) {
		printf("%s %d\n", (char *)args, i);
		swapcontext(&cping, &cpong);
	}
	printf("%s FIM.\n", args);
	swapcontext(&cping, &cmain);
}

void pong(void *args)
{
	int i;
	printf("%s iniciado.\n", (char *) args);
	for (i=0; i<4; i++) {
		printf("%s %d\n", (char *)args, i);
		swapcontext(&cpong, &cping);
	}
	printf("%s FIM.\n", args);
	swapcontext(&cpong, &cmain);
}

int main(int argc, char **argv)
{
	printf("Main inicio.\n");

	char *stack1 = 0;
	getcontext(&cping);
	stack1 = malloc(STACK_SIZE);
	if (stack1) {
		cping.uc_stack.ss_sp    = stack1;
		cping.uc_stack.ss_size  = STACK_SIZE;
		cping.uc_stack.ss_flags = 0;
		cping.uc_link = 0;
	}
	else {
		perror("Erro na criacao da pilha:\n");
		exit(EXIT_FAILURE);
	}
	makecontext(&cping, (void *)(*ping), 1, "PING: ");
	
	char *stack2 = 0;
	getcontext(&cpong);
	stack2 = malloc(STACK_SIZE);
	if (stack2) {
		cpong.uc_stack.ss_sp    = stack2;
		cpong.uc_stack.ss_size  = STACK_SIZE;
		cpong.uc_stack.ss_flags = 0;
		cpong.uc_link = 0;
	}
	else {
		perror("Erro na criacao da pilha:\n");
		exit(EXIT_FAILURE);
	}
	makecontext(&cpong, (void *)(*pong), 1, "PONG: ");

	swapcontext(&cmain, &cping);
	swapcontext(&cmain, &cpong);

	printf("MAIN FIM.\n");
	free(stack2);
	free(stack1);
	
	return 0;
}
