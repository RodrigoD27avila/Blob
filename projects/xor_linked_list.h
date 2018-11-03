#ifndef XOR_LINKED_LIST_H_INCLUDED
#define XOR_LINKED_LIST_H_INCLUDED

typedef unsigned long u_long;

typedef struct
{
	void *data;
	void *address;

} xor_linked_list_t;

void xor_linked_list_append(xor_linked_list_t *list, void *data);
void xor_linked_list_remove(xor_linked_list_t *list, void *data);

#endif /*XOR_LINKED_LIST_H_INCLUDED*/
