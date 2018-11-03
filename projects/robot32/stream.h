#ifndef STREAM_H_INCLUDED
#define STREAM_H_INCLUDED

#include <SDL.h>
#include "vector.h"

typedef vector_t stream_t;

void stream_init(stream_t *stream);
void stream_destroy(stream_t *stream);

void stream_pushback(stream_t *stream,
	const unsigned char *data, size_t bytes);

char *stream_get(stream_t *stream);

#endif // STREAM_H_INCLUDED
