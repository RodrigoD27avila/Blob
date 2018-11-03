#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long int Uint64;

static Uint64 results_capacity;
static Uint64 results_size;
static Uint64 *results;

static Uint64 table_capacity;
static Uint64 table_size;
static Uint64 *table;

static Uint64 *allocate_more_space(Uint64 **array,
		Uint64 *capacity, Uint64 size)
{
	size_t bytes = sizeof(Uint64);
	Uint64 *newarray = realloc(*array, (size * bytes) + (100 * bytes));
	(*capacity) = *capacity += 100;
	return newarray;	
}

static void add_to_array(Uint64 number, Uint64 *size,
	Uint64 *capacity, Uint64 **array)
{
	if ((*capacity)-1 == *size) {
		(*array) = allocate_more_space(array, capacity, *size);
	}

	(*array)[*size] = number;
	(*size)         = (*size) + 1;
}

static void add_to_table(number)
{
	Uint64 i, j;
	for (i=0; i<results_size; i++) {
		for (j=0; j<results_size; j++) {

			Uint64 mynumber = results[i]
				+ results[j]
				+ number;

			add_to_array(mynumber, &table_size,
				&table_capacity, &table);
		}
	}
	
	for (i=0; i<results_size; i++) {
			
		Uint64 mynumber = results[i]
			+ number
			+ number;

		add_to_array(mynumber, &table_size,
			&table_capacity, &table);
	}
		
	add_to_array(number+number+number, &table_size,
		&table_capacity, &table);

}

static void add_to_results(number)
{
	add_to_array(number, &results_size, &results_capacity, &results);
}

static void three(Uint64 number)
{
	Uint64 i, j;
	for (i=0; i<results_size; i++) {
		for (j=0; j<results_size; j++) {

			Uint64 mynumber = results[i]
				+ results[j]
				+ number;

			Uint64 l;
			for (l=0; l<table_size; l++) {
				if (table[l] == mynumber) {
					return;
				}
			}
		}
	}
	
	printf("%llu\n", number);

	add_to_results(number);
	add_to_table(number);
}

int main()
{
	results          = malloc(100 * sizeof(Uint64));
	results[0]       = 1;
	results_size     = 1;
	results_capacity = 100;
	
	table          = malloc(100 * sizeof(Uint64));
	table[0]       = 4;
	table_size     = 1;
	table_capacity = 100;

	Uint64 i;
	for (i=3; ;i+=2) {
		three(i);
	}

	free(results);
	free(table);
}
