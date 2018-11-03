#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	unsigned int bytes = (list->capacity * list->datasize);
	unsigned int i;

	for (i=1; i < bytes; i+=list->datasize) {
		// offset bytes
		unsigned int offset = (i * list->datasize);

		// copy offset destination to tmp
		memcpy(tmp, list->data + offset, list->datasize);

		// copy array[0] to offset destination
		memcpy(list->data + offset, list->data, list->datasize);

		// copy tmp to array[0];
		memcpy(list->data, tmp, list->datasize);
	}

	// free tmp
	free(tmp);
}
