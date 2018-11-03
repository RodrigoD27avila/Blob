#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <signal.h>
#include <unistd.h>

static int seq[256];
static int  in[256];

void print_seq()
{
		int k;
		for (k=0; k<200; k++) {
			printf("%i", seq[k]);
		}
		printf("\n");
}


void sig_handler(int signo)
{
	if (signo == SIGUSR1) {
		print_seq();
	}
}


void solve(int ival) {

	//if (ival == 200) {
		print_seq();
	//}


	int i;
	for (i=0; i<10;i++) {
		int index = (seq[ival-1] * 10) + i;
		if (in[index] == 0) {

			in[index] = 1;
			seq[ival] = i;
			solve(ival+1);
			in[index] = 0;
		}
	}
}


int main()
{
	signal(SIGUSR1, sig_handler);

	seq[0] = 0;
	solve(1);
	return 0;
}

