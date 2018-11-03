#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pstring.h"
#include "vector.h"

void string_init(string_t *string)
{
	vector_init(string, 1, 1, 1);
}

void string_destroy(string_t *string)
{
	vector_destroy(string);
}

void string_setconst(string_t *string, const char *str)
{
	size_t len  = strlen(str);
	Sint32 size = len - string->capacity;
	if (size > 0) {
		vector_realloc(string, size+1);
	}
	memcpy(string->data, str, len);
	memset(string->data+len, 0, string->capacity - len);
	string->size = len;
}

void string_catconst(string_t *string, const char *str)
{
	if (string->size == 0) {
		string_setconst(string, str);
	} else {
		size_t len = strlen(str);
		if (len > 0) {
			Sint32 size = ((string->size + len) - string->capacity);
			if (size > 0) {
				vector_realloc(string, size+1);
			}

			memcpy(string->data+string->size, str, len);
			memset(string->data+string->size+len, 0,
				string->capacity - (string->size+len));

			string->size += len;
		}
	}
}

void string_catstring(string_t *s1, const string_t *s2)
{
	string_catconst(s1, string_get(s2));
}

int string_cmp(const string_t *s1, const string_t *s2)
{
	uint32_t size = (s1->size < s2->size) ? s1->size : s2->size;

	uint32_t i;
	for (i=0; i<size; i++) {
		if (string_at(s1, i) > string_at(s2, i)) {
			return 1;
		} else {
			if (string_at(s1, i) < string_at(s2, i)) {
				return -1;
			}
		}
	}

	if (s1->size == s2->size) {
		return 0;
	} else {
		if (s1->size == size) {
			return -1;
		} else {
			return 1;
		}
	}
}

void string_catchar(string_t *string, char c)
{
	vector_pushback(string, &c);
}

char *string_get(const string_t *string)
{
	return (char *)string->data;
}

char string_at(const string_t *string, uint32_t index)
{
	char *c = vector_at(string, index);
	return c[0];
}

void string_zero(string_t *string)
{
	memset(string->data, 0, string->capacity);
}
