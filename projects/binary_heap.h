#ifndef BINARY_HEAP_INCLUDED
#define BINARY_HEAP_INCLUDED

#define INF 0x7fffffff

typedef int *binary_heap;

void binary_heap_init(binary_heap heap);
int  binary_heap_find_min   (binary_heap heap);
int  binary_heap_delete_min (binary_heap heap);
void binary_heap_insert     (binary_heap heap);

#endif // BINARY_HEAP_INCLUDED
