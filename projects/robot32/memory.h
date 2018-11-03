#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED

#include <SDL.h>

#ifdef OS_INVADERS_DEBUG
#	define memory_Alloc(s) __memory_TraceAlloc(s, __FILE__, __LINE__)
#	define memory_Free(p)  __memory_TraceFree(p, __FILE__, __LINE__)
#else
#	define memory_Alloc(s) __memory_Alloc(s)
#	define memory_Free(p)  __memory_Free(p)
#endif

/* allocate memory and exit if unable to allocate */
void *__memory_Alloc(size_t bytes);

/* free memory */
void __memory_Free(void *obj);

/* alloc memory */
void __memory_TraceAlloc(size_t bytes, const char *file, unsigned int line);

/* free memory*/
void __memory_TraceFree(void *obj, const char *file, unsigned int line);

#endif /* MEMORY_H_INCLUDED */
