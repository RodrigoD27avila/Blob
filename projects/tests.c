#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES 2000

typedef signed long long int Sint;

static const int max = 36;
static const int numbers[] = {
	1,
	2,
	6,
	22,
	56,	
	154,
	369,
	857,
	1425,
	2604,
	4968,
	8195,
	13664,
	22433,
	28170,
	47689,
	65546,
	96616,
	146249,
	202508,
	266268,
	364835,
	450309,
	585329,
	773001,
	986340,
	1162749,
	1472660,
	1993181,
	2275963,
	3012657,
	3552308,
	4590960,
	5404184,
	6601788,
	7893271,
	9340878,
	11297830,
};
static Sint table_capacity;
static Sint table_size;
static Sint *table;

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

static Sint *allocate_more_space()
{
        size_t bytes = sizeof(Sint);
        Sint *newarray = realloc(table, (table_size * bytes)
			 + (BYTES * bytes));

        table_capacity += BYTES;
        return newarray;        
}

static void add_to_array(Sint number)
{
        if (table_capacity-1 == table_size) {
                table = allocate_more_space();
        }

        table[table_size] = number;
        table_size       += 1;
}

static void add_to_table()
{
        Sint i, j, k;
        for (i=0; i < max; i++) {
                for (j=0; j<max; j++) {
                        for (k=0; k<max; k++) {
                		Sint mynumber = 99
        	                	+ numbers[i]
	                                + numbers[j]
                                        + numbers[k];
        
                               	add_to_array(mynumber);
                        }
                }
        }
        
	for (i=0; i < max; i++) {
                for (j=0; j<max; j++) {
                	Sint mynumber = 99
        	               	+ numbers[i]
	                        + numbers[j]
                                + 99; 
        
                         add_to_array(mynumber);
                }
        }
	
	for (i=0; i < max; i++) {
               	Sint mynumber = 99
                       	+ numbers[i]
	                + 99
                        + 99; 
        
                add_to_array(mynumber);
        }

	add_to_array(99+99+99+99);
}

static void check_prime()
{
	int nonprimes = 0;

	int i, j;	
	for (i=0; i<max; i++) {
		int number = numbers[i];
		int last = nonprimes;

		for (j=3; j<number;j+=2) {
			if ((number % j) == 0) {
				nonprimes+=1;
				break;
			}
		}

		if (last == nonprimes) {
			printf("%i is prime.\n", number);
		}
	}

	printf("primes     = %i\n", max - nonprimes);
	printf("non primes = %i\n", nonprimes);
}

static void check_percent()
{
	int i;
	for (i=1; i<max;i++) {
		printf("%10i to %10i = %3.10f\n",
			numbers[i-1], numbers[i],
			(float)(numbers[i-1]) / (numbers[i]));
	}
}

static void check_if_is_true()
{
	add_to_table();
	qsort(table, table_size, sizeof(Sint), compar);

	Sint i;
	for (i=0; i<table_size;i++) {
		printf("%Lu\n", table[i]);
	}
}

int main()
{
	table          = malloc(BYTES * sizeof(Sint));
	table_capacity = BYTES;
	table_size     = 0;

	check_prime();
	check_percent();

	return 0;
}
