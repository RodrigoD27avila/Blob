/*See Copyright Notice in dat.h*/

#ifndef DATERROR_H_INCLUDED
#define DATERROR_H_INCLUDED

#include <stdlib.h>

#define DAT_NO_ERROR 0
#define DAT_EALLOC   1
#define DAT_ENULL    2
#define DAT_EFILE    3
#define DAT_ESIZE    4
#define DAT_EMAX     5
#define DAT_EWRITE   6
#define DAT_EREAD    7
#define DAT_ESEEK    8

#ifdef __cplusplus
extern "C" {
#endif

char *DAT_GetErrorString(int error);

#ifdef __cplusplus
}
#endif

#endif /*DATERROR_H_INCLUDED*/
