#include "xor_linked_list.h"

#include <stdio.h>

void xor_linked_list_append(xor_linked_list_t *list, void *data)
{
	list->data = data;

	if (list->address)
	{
		if (list->address != list)
		{
			printf("\\0/!!\n");
			return;	
		}
		
		list->address = list;
	}

	list->address = list;
	
}

void xor_linked_list_remove(xor_linked_list_t *list, void *data);

