/*See Copyright Notice in dat.h*/

#include "daterror.h"

char *DAT_GetErrorString(int error)
{
	switch (error) {
	case (-DAT_EALLOC):
		return "ERROR: there was a problem when allocating memory.";
	case (-DAT_ENULL):
		return "ERROR: null pointer.";
	case (-DAT_EFILE):
		return "ERROR: there is a problem with your file,"
			" maybe it does not exist.";
	case (-DAT_ESIZE):
		return "ERROR: files must be between 1 byte and 2 gigabytes.";
	case (-DAT_EMAX):
		return "ERROR: is only possible to add 2 ^ 14 entries.";
	case (-DAT_EWRITE):
		return "ERROR: cannot write data to file.";
	case (-DAT_EREAD):
		return "ERROR: cannot read data from file.";
	case (-DAT_ESEEK):
		return "ERROR: cannot set the file position.";
	}
	return NULL;
}
