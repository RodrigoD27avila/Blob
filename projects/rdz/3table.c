#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "results.h"

typedef struct {
	int number;
	int n1, n2;	
}Sum2;

Sum2 g_bigtable[65535];

void create_bigtable()
{
	// clear big table
	memset(g_bigtable, 0, 65535);

	// loop 
	int i, j, k = 0;
	for (i=0; i<256; i++) {
		for (j=0; j<256; j++) {
			Sum2 *s = &g_bigtable[k];
			s->number = gresults[i] + gresults[j];
			s->n1     = i;
			s->n2     = j; 

			k += 1;
		}
	}
}

void print_bigtable()
{
	int i;
	for (i=0; i< 65535 ; i++) {
		Sum2 *s = &g_bigtable[i];
		printf("%7i: %3i,%3i\n", s->number, s->n1, s->n2);
	}
}

void print_newtable()
{
	int i, j;
	for (i=0; i<65535; i++) {	
		for (j=0;j<256; j++) {
			Sum2 *s = &g_bigtable[i];
			printf("%15i: %3i,%3i,%3i\n", s->number + gresults[j],
				 s->n1, s->n2, j);
		}
	}
}

int main(int argc, char **argv)
{
	create_bigtable();
	print_newtable();
	return 0;
}
