#include "rwnum.h"

static RWN_Uint64 g_index = 0;
static int overflow       = 0;

int RWN_ArrayListInit(RWN_ArrayList *list)
{
	memset(list, 0, sizeof(RWN_ArrayList));
	list->size   = 0;
	list->lenght = 0;
	return 0;
}

int RWN_ArrayListDestroy(RWN_ArrayList *list)
{
	free(list->array);
	memset(list, 0, sizeof(RWN_ArrayList));

	return 0;
}

int RWN_ArrayListAdd(RWN_ArrayList *list, RWN_Uint64 number)
{
	if (list->lenght >= list->size) {
		list->array = realloc(list->array,
			(sizeof(RWN_Uint64) * RWN_ALALLOC) +
			(sizeof(RWN_Uint64) * list->size));

		if (list->array == NULL) return -1;

		list->size += RWN_ALALLOC;
	}

	list->array[list->lenght] = number;
	list->lenght += 1;

	return 0;
}

inline int RWN_SearchNumber(RWN_ArrayList *list, RWN_Uint64 number)
{
	RWN_Uint64 i;
	for (i = g_index; i < list->lenght; i++) {
		if (list->array[i] == number) {
			return -1;
		}
	}

	return 0;
}

static void rwn_calculate(RWN_Uint64 global, RWN_ArrayList *results,
	RWN_ArrayList *table)
{
	RWN_Uint64 tmpnum, i;
	for (i = 0; i < results->lenght; i++) {
	
		tmpnum = (global + results->array[i]); 
	
		if ((RWN_SearchNumber(table, tmpnum)) < 0) {
			return;
		}
	}

	/*last*/

	tmpnum  = global + global;

	if ((RWN_SearchNumber(table, tmpnum)) < 0) {
		return;
	}

	printf("%Lu\n", global);
	RWN_ArrayListAdd(results, global);

	/*add numbers to table*/

	for (i = 0; i < results->lenght; i++) {
		tmpnum  = global + results->array[i];
		RWN_ArrayListAdd(table, tmpnum);
	}

	/* RWN_SortArrayList(table, g_index); */
	RWN_SetArrayIndex(table, g_index, global);
	
	return;
}

int RWN_Calculate(RWN_Uint64 global, RWN_ArrayList *results,
	RWN_ArrayList *table)
{
	for (;;) {
		global += 2;
		rwn_calculate(global, results, table);
	}
	return 0;
}

int RWN_SaveListNum(RWN_ArrayList *list, FILE *file)
{	
	rewind(file);
	RWN_Uint64 i ;
	for (i = 0; i < list->lenght; i++) {
		fprintf(file, "%Lu\n", list->array[i]);
	}
	return 0;
}

RWN_Uint64 rwn_get_int64(char *str)
{
	char buffer[20];
	memset(buffer, 0, 20);

	int  len = strlen(str);

	RWN_Uint64 number = 0;

	if (len <= 1) {
		fprintf(stderr, "Unable to convert to int64\n");
		exit(EXIT_FAILURE);
	}

	memcpy(buffer, str, len -1);
	number = atoll(buffer);
	return number;
}

int RWN_ArrayListLoadFromFile(RWN_ArrayList *list, FILE *file)
{
	char buffer[20];
	memset(buffer, 0, 20);

	while ((fgets(buffer, 19, file)) != NULL) {
		RWN_Uint64 number = rwn_get_int64(buffer);
		RWN_ArrayListAdd(list, number);
		memset(buffer, 0, 20);
	}

	return 0;
}

int RWN_SetArrayIndex(RWN_ArrayList *list,RWN_Uint64 lastindex,
	RWN_Uint64 number)
{
	RWN_Uint64 i;
	for (i=lastindex; i<list->lenght; i++) {
		if (list->array[i] > number) {
			return 0;
		}

		g_index = i;
	}

	return 0;
}

RWN_Uint64 RWN_GetGlobalIndex()
{
	return g_index;
}

static int compar(const void *n1, const void *n2)
{
	const RWN_Uint64 *r1 = (RWN_Uint64 *)n1;
	const RWN_Uint64 *r2 = (RWN_Uint64 *)n2;

	if (*r1 >= 2147483647 || *r2 >= 2147483647) {
		overflow = 1;
		fprintf(stderr, "!! OVERFLOW !!\n");
		return 0;
	}

	return (int)(*r1 - *r2);
}

void RWN_SortArrayList(RWN_ArrayList *list, RWN_Uint64 index)
{
	if (!overflow) {
		qsort(list->array, sizeof(RWN_Uint64),
			list->lenght, compar);	
	}
	return;	
}
