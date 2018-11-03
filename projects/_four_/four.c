#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>

#define BYTES 2000
#define INC 1

#if defined WIN32 || defined __WIN32__ 
	typedef signed int Sint;

#else
	typedef signed long long int Sint;

#endif

static Sint thenumber;
static Sint thecount;

static FILE *file;
static Sint results_capacity;
static Sint results_size;
static Sint *results;

static Sint table_capacity;
static Sint table_size;
static Sint table_index;
static Sint *table;

static Sint temp_capacity;
static Sint temp_size;
static Sint *temp;

static int compar(const void *v1, const void *v2)
{
	const Sint *r1 = (const Sint *)v1;
	const Sint *r2 = (const Sint *)v2;

	if (*r1 > *r2) {
		return 1;
	}
	else if (*r1 < *r2) {
		return -1;
	}

	return 0;
}

static Sint *allocate_more_space(Sint **array,
		Sint *capacity, Sint size)
{
	size_t bytes = sizeof(Sint);
	Sint *newarray = realloc(*array, (size * bytes) + (BYTES * bytes));
	(*capacity) += BYTES;
	return newarray;	
}

static void add_to_array(Sint number, Sint *size,
	Sint *capacity, Sint **array)
{
	if ((*capacity)-1 == *size) {
		(*array) = allocate_more_space(array, capacity, *size);
	}

	(*array)[*size] = number;
	(*size)         = (*size) + 1;
}

static void find_next_table_index(Sint number)
{
	Sint i;
	for (i=0; i<table_size; i++) {
		if (table[i] > number) {
			table_index = i;
			return;
		}
	}
}

static void add_to_results(Sint number)
{
	add_to_array(number, &results_size, &results_capacity, &results);
}

static void add_to_table(Sint *array, Sint size)
{
	// zero table
	memset(table, 0, table_capacity);
	table_size = 0;

	Sint k;
	Sint last = -1;
	for (k=0; k<size; k++) {

		Sint mynumber = array[k];
		if (mynumber == last)
			continue;
		last = mynumber;

		add_to_array(mynumber, &table_size,
			&table_capacity, &table);
	}
	
	qsort(table, table_size, sizeof(Sint), compar);
}

inline static bool contains(Sint *array, Sint size)
{
	Sint k, l;
	Sint last = -1;

	for (k=0; k<size; k++) {

		Sint mynumber = array[k];
		if (mynumber == last)
			continue;
		last = mynumber;

		for (l=table_index; l < table_size; l++) {
		 	if (table[l] == (mynumber+thecount)) {
				return true;
			}
		}
	}

	return false;
}

static void create_first_table(Sint **array, Sint *size, Sint *capacity) {

	Sint i, j, k, l;
	for (i=0; i< results_size; i++) {
		for (j=0; j< results_size; j++) {
			for (k=0; k< results_size; k++) {
				for (l=0; l< results_size; l++) {

					Sint mynumber = results[i]
						+ results[j]
						+ results[k]
						+ results[l];

					add_to_array(mynumber, size,
						capacity, array);
				}
			}
		}
	}

	qsort(*array, *size, sizeof(Sint), compar);
}

static void create_temporary_table(Sint number, Sint **array,
		Sint *size, Sint *capacity) {
		
	// clean table
	memset((*array), 0, (*capacity));
	(*size) = 0;


	Sint i, j, k;
	for (i=0; i< results_size; i++) {
		for (j=0; j< results_size; j++) {
			for (k=0; k< results_size; k++) {

				Sint mynumber = results[i]
					+ results[j]
					+ results[k]
					+ number;

				add_to_array(mynumber, size,
					capacity, array);
			}
		}
	}

	qsort(*array, *size, sizeof(Sint), compar);
}

static void create_full_table()
{
	Sint *first_temp          = malloc(BYTES * sizeof(Sint));
	Sint first_temp_size      = 0;
	Sint first_temp_capacity  = BYTES;
	create_first_table(&first_temp, &first_temp_size,
			&first_temp_capacity);

	add_to_table(first_temp,first_temp_size);
	free(first_temp);
}


static void four()
{
	// if contais in table, return
	while (contains(temp, temp_size)) {
		thecount += INC;
	}

	thenumber += thecount;
	add_to_results(thenumber);

	// create full table
	create_full_table();

	// next index
	find_next_table_index(thenumber);

	// set the count to zero
	thecount  = 0;
	
	// print number
	printf("%llu\n", thenumber);
}

Sint get_sint(char *str)
{
        char buffer[20];
        memset(buffer, 0, 20);

        int  len = strlen(str);

        Sint number = 0;

        if (len <= 1) {
                fprintf(stderr, "Unable to convert to Sint\n");
                exit(EXIT_FAILURE);
        }

        memcpy(buffer, str, len -1);
        number = atoll(buffer);
        return number;
}


void load_from_file()
{
        char buffer[20];
        memset(buffer, 0, 20);

        while ((fgets(buffer, 19, file)) != NULL) {
                Sint number = get_sint(buffer);
		add_to_array(number, &results_size,
			&results_capacity, &results);
                memset(buffer, 0, 20);
        }
}

void cleanup()
{
	free(results);
	free(table);
}

void save()
{
        rewind(file);
       	Sint i;
        for (i=0; i < results_size; i++) {
                fprintf(file, "%Lu\n", results[i]);
        }

	fflush(file);
	fclose(file);
}

void save_and_quit()
{
	save();
	cleanup();
	exit(EXIT_SUCCESS);
}

void print_number()
{
	printf(">> %Lu\n", thenumber);
}


int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("USAGE: %s <results_file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// intialize results array
	results          = malloc(BYTES * sizeof(Sint));
	results_capacity = BYTES;

	// open results file
	file = fopen(argv[1], "rw+");
	if (file == NULL) {
		printf("Unable to load results file.\n");
		exit(EXIT_FAILURE);
	}

	printf("Loading results from file\n");
	// load results from file
	load_from_file();
	

	// creatin temp table
	printf("Creating temp.\n");
	temp           = malloc(BYTES * sizeof(Sint));
	temp_size      = 0;
	temp_capacity  = BYTES;


	// initialize table array	
	table          = malloc(BYTES * sizeof(Sint));
	table_size     = 0;
	table_capacity = BYTES;
	table_index    = 0;

	printf("Creating table.\n");
	create_full_table();

	signal(SIGINT , save_and_quit);
        signal(SIGTERM, save_and_quit);
        signal(SIGKILL, save_and_quit);
        signal(SIGKILL, save_and_quit);
        signal(SIGUSR1, print_number);

	thenumber = results[results_size-1];	
	// next index
	find_next_table_index(thenumber);
	// create temp table
	
	printf("The table length is %Lu.\n", table_size);
	printf("The table index  is %Lu.\n", table_index);
	printf("Initilized.\n\n");
	print_number();
	
	while (true) {
		thenumber += INC;
	
		add_to_results(thenumber);
	
		// create temporary table
		create_temporary_table(thenumber,
			 &temp, &temp_size, &temp_capacity);

		results_size -= 1;
		four();
	}

	save_and_quit();
	return 0;
}
