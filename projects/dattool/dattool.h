/*See Copyright Notice in dat.h*/

#ifndef DATTOOL_H_INCLUDED
#define DATTOOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "datconf.h"

#define DAT_MAX_ENTRIES  16384 /*2^14*/
#define DAT_MAGIC_SIZE   16
#define DAT_ID_SIZE      6
#define DAT_VERSION_SIZE 4
#define DAT_NAME_SIZE    64

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
	DAT_Sint32  id;
	char   name[DAT_NAME_SIZE];
	DAT_Sint32  size;
	DAT_Sint64  offset;

	char *fullname;
} DAT_FileEntry;

typedef struct { 
	char   id[DAT_ID_SIZE];
	char   version[DAT_VERSION_SIZE];
	DAT_Sint32  num_entries;  
} DAT_Header;

typedef struct {
	char     magic[DAT_MAGIC_SIZE];
	char          *name;
	DAT_Header    *header;
	DAT_FileEntry *table[DAT_MAX_ENTRIES];
} DAT;

int        DAT_Init(DAT *dat, char *name, char *magic,
		char *id, char *version);

int        DAT_Destroy(DAT *dat);

int        DAT_PushBack(DAT *dat, char *entryname);
int        DAT_Write(DAT *dat);

int        DAT_GetHeaderInfo(char *id, char *version,
		DAT_Sint32 *num_entries, FILE *dat);

int        DAT_GetEntryInfo(DAT_Sint32 entry, char *entryname, DAT_Sint32 *size,
		DAT_Sint64 *offset, FILE *dat);

int        DAT_GetEntryIndex(char *entryname, DAT_Sint32 *entry, FILE *dat);
int        DAT_GetData(char *buffer, int len, long pos, FILE *dat);

int        DAT_ParseFilePath(char *path, char **newname);

#ifdef __cplusplus
}
#endif

#endif /*DATTOOL_H_INCLUDED*/
