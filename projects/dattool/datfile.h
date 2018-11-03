/*See Copyright Notice in dat.h*/

#ifndef DATFILE_H_INCLUDED
#define DATFILE_H_INCLUDED

#include "datconf.h"

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif


#if   defined DAT_OS_WINDOWS
	#include <windows.h>
	#define DAT_DIR_SEPARATOR '\\'
/*END DAT_OS_WINDOWS*/
#elif defined DAT_OS_POSIX
	#include <sys/stat.h>
	#include <sys/types.h>
	#include <errno.h>
	#define DAT_DIR_SEPARATOR '/'
/*END DAT_OS_POSIX*/
#endif


int DAT_GetFileSize(DAT_Sint32 *size, char *filename);


#ifdef __cplusplus
}
#endif

#endif /*DATFILE_H_INCLUDED*/
