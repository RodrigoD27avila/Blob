#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
	uint32_t capacity;
	uint32_t size;
	size_t   nmemb;
	int      *data;
} vector_t;


void vector_init(vector_t *vector, size_t nmemb)
{
	vector->capacity = 100;
	vector->size     = 0;
	vector->nmemb    = nmemb;
	vector->data     = calloc(100, nmemb);
}

void vector_destroy(vector_t *vector)
{
	vector->capacity = 0;
	vector->size     = 0;
	vector->nmemb    = 0;

	free(vector->data);
	vector->data     = NULL;
}

void vector_realloc(vector_t *vector, uint32_t size)
{
	if (vector->size+1 == vector->capacity) {
		void * data = realloc(vector->data,
			(vector->size+100)*vector->nmemb);

		vector->data = data;
	}

	vector->capacity += size;
}

void vector_pushback(vector_t *vector, void *value)
{
	vector_realloc(vector, 100);
	memcpy(vector->data+(vector->size * vector->nmemb),
		value, vector->nmemb);
	vector->size += 1;
}

void *vector_at(vector_t *vector, uint32_t index)
{
	return vector->data+(index * vector->nmemb);
}

int main()
{
	vector_t vector;
	vector_init(&vector, sizeof(int));

	int i;
	for (i=0; i<1000; i++) {
		vector_pushback(&vector, &i);
	}

	vector_destroy(&vector);

	return 0;
}
