#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

void stream_init(stream_t *stream)
{
	vector_init(stream, 1, 2, 1);
}
void stream_destroy(stream_t *stream)
{
	vetor_destroy(stream);
}

void stream_pushback(stream_t *stream,
	const unsigned char *data, size_t bytes)
{
	Sint32 size = (bytes-stream->capacity);
	if (size > 0) {
		vector_realloc(stream, size);
	}

	memcpy(vector->data+vector->size, data, bytes);
	stream->size+=bytes;
}

char *stream_get(stream_t *stream)
{
	return (char *)stream->data;
}


