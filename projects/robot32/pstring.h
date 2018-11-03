#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "vector.h"

typedef vector_t string_t;

void string_init(string_t *string);
void string_destroy(string_t *string);

void string_setconst(string_t *string, const char *str);
void string_catconst(string_t *string, const char *str);
void string_catstring(string_t *s1, const string_t *s2);
void string_catchar(string_t *string, char c);

int string_cmp(const string_t *s1, const string_t *s2);

char string_at(const string_t *string, uint32_t index);

char *string_get(const string_t *string);
void string_zero(string_t *string);


#endif // STRING_H_INCLUDED
