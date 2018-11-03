#ifndef RWNUM_H_INCLUDED
#define RWNUM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RWN_ALALLOC 100

typedef unsigned long long int RWN_Uint64;

typedef struct RWN_ArrayList RWN_ArrayList;

struct RWN_ArrayList{
	RWN_Uint64 *array;
	RWN_Uint64 size;
	RWN_Uint64 lenght;
	
};

int RWN_Calculate(RWN_Uint64 global, RWN_ArrayList *results, RWN_ArrayList *table);

int RWN_ArrayListInit(RWN_ArrayList *list);
int RWN_ArrayListDestroy(RWN_ArrayList *list);
int RWN_ArrayListAdd(RWN_ArrayList *list, RWN_Uint64 number);

int RWN_SearchNumber(RWN_ArrayList *list, RWN_Uint64 number);

int RWN_SaveListNum(RWN_ArrayList *list, FILE *file);
int RWN_SaveListPrimes(RWN_ArrayList *list, FILE *file);

int RWN_ArrayListLoadFromFile(RWN_ArrayList *list, FILE *file);

int RWN_SetArrayIndex(RWN_ArrayList *list,RWN_Uint64 lastindex,
	RWN_Uint64 number);

RWN_Uint64 RWN_GetGlobalIndex();

void RWN_SortArrayList(RWN_ArrayList *list, RWN_Uint64 index);

#endif /*RWNUM_H_INCLUDED*/
