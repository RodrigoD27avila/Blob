#include "rdzcompress.h"
#include "results.h"
#include "table.h"

#define BUFFER_SIZE 65792
static char buffer[BUFFER_SIZE+2];

int RDZ_GetBytes(unsigned char *byte1, unsigned char *byte2, FILE *file)
{
	unsigned char buf[2];
	size_t bytes = 0;

	if ((bytes = fread(buf, 1, 2, file)) <= 0) {
		return -1;
	}

	*byte1 = buf[0];	
	*byte2 = buf[1];
	return 0;
}

int RDZ_TransformBytes(unsigned char byte1, unsigned char byte2, int *integer)
{
	int number = (gresults[byte1] + gresults[byte2]);

	int index;
	for (index=0; number != gtable[index]; index++);

	int result = (index * 2);
	if (byte1 < byte2) {
		result -= 1;
	}

	*integer = result;

	return 0;
}

int RDZ_PrintString(int integer)
{
	memset(buffer, 0, BUFFER_SIZE+2);
	buffer[0] = '1';
	memset(buffer+1, '0' , integer+1);

	fprintf(stdout,"%s", buffer);
	fflush(stdout);

	return 0;
}
