#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include "rwnum.h"

RWN_Uint64 global;

RWN_ArrayList *results;
RWN_ArrayList *table;

FILE *outresults;
FILE *outtable;

void init(char *nameresults, char *nametable)
{
	results = malloc(sizeof(RWN_ArrayList));
	if (results == NULL) {
		goto exit_failure;
	}
	RWN_ArrayListInit(results);

	table = malloc(sizeof(RWN_ArrayList));
	if (table == NULL) {
		goto exit_failure;
	}
	RWN_ArrayListInit(table);

	global = 0;

	outresults = fopen(nameresults, "rw+");
	if (outresults == NULL) {
		goto exit_failure;
	}
	
	outtable = fopen(nametable, "rw+");
	if (outtable == NULL) {
		goto exit_failure;
	}
	
	return;
	

exit_failure:
	if (results) free(results);
	if (table)   free(table);
	exit(EXIT_FAILURE);
	return;
}

static void print_global_index()
{
	printf("GLOBAL = %Lu\n", RWN_GetGlobalIndex());
	return;	
}

static void quit()
{
	RWN_ArrayListDestroy(results);
	RWN_ArrayListDestroy(table);
	free(results);
	free(table);

	fclose(outresults);
	fclose(outtable);

	exit(EXIT_SUCCESS);
	return;
}


static void save_and_quit()
{
	RWN_SaveListNum(results, outresults);
	RWN_SaveListNum(table, outtable);
	fflush(outresults);
	fflush(outtable);
	quit();
	return;
}


int main(int argc, char **argv)
{
	if (argc < 3) {
		printf("USAGE: %s <results_file> <table_file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
 
	init(argv[1], argv[2]);

	signal(SIGINT , save_and_quit);
	signal(SIGTERM, save_and_quit);
	signal(SIGUSR1, print_global_index);
	signal(SIGKILL, quit);

	RWN_ArrayListLoadFromFile(results, outresults);
	RWN_ArrayListLoadFromFile(table, outtable);

	global = results->array[results->lenght-1];
	printf("GLOBAL = %Lu\n", global);

	RWN_SetArrayIndex(table, 0, global);
	RWN_Calculate(global, results, table);
	save_and_quit();
	return 0;
}
