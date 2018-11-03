#ifndef RDZCOMPRESS_H_INCLUDED
#define RDZCOMPRESS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int RDZ_GetBytes(unsigned char *byte1, unsigned char *byte2, FILE *file);

int RDZ_TransformBytes(unsigned char byte1, unsigned char byte2, int *integer);

int RDZ_PrintString(int integer);

#endif /*RDZCOMPRESS_H_INCLUDED*/
