/*See Copyright Notice in dat.h*/

#include "dattool.h"
#include "datfile.h"
#include "daterror.h"

static int DAT_TABLE_ENTRY_BYTES = (4+DAT_NAME_SIZE+4+8);
static int DAT_RW_BUFFER         = 500;

int DAT_Init(DAT *dat, char *name, char *magic,
	char *id, char *version)
{
	DAT_Header *header = malloc(sizeof(DAT_Header));
	if (header == NULL) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		return -DAT_EALLOC;
	}

	memset(header, 0, sizeof(DAT_Header));

	strncpy(header->id     , id     , DAT_ID_SIZE-1);
	strncpy(header->version, version, DAT_VERSION_SIZE-1);
	strncpy(dat->magic     , magic  , DAT_MAGIC_SIZE-1);

	dat->name   = name;
	dat->header = header;

	return 0;
}

int DAT_Destroy(DAT *dat)
{
	int i;
	for (i=0; i < dat->header->num_entries; i++) {
		free(dat->table[i]);
	}
	
	free(dat->header);
	memset(dat, 0, sizeof(DAT));
	return 0;
}

int DAT_PushBack(DAT *dat, char *entryname)
{
	int error = 0;

	DAT_FileEntry *entry = malloc(sizeof(DAT_FileEntry));
	if (entry == NULL) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		error = -DAT_ENULL;
		goto end_with_error;
	}
	memset(entry, 0, sizeof(DAT_FileEntry));

	static index;
	if (index >= DAT_MAX_ENTRIES) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		error = -DAT_EMAX;
		goto end_with_error;
	}

	dat->header->num_entries = index+1;
	entry->fullname          = entryname;
	entry->id                = index;

	char *newname = NULL;
	if ((error = DAT_ParseFilePath(entry->fullname, &newname)) < 0) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		goto end_with_error;
	}

	strncpy(entry->name, newname, DAT_NAME_SIZE-1);

	if ((error = DAT_GetFileSize(&entry->size, entryname)) < 0) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		goto end_with_error;
	}

	if (entry->size <= 0) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		error = -DAT_ESIZE;
		goto end_with_error;
	}

	dat->table[index] = entry;
	index += 1;

	return 0;

end_with_error:
	DAT_Destroy(dat);
	return error;
}

static int dat_create_table(DAT *dat, int bytes, char **buffer, long pos)
{
	
	char *newbuffer = malloc(bytes);
	if (newbuffer == NULL) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		return -DAT_EALLOC;
	}
	memset(newbuffer, 0, bytes);

	DAT_Sint64 file_pos = pos + bytes;

	int i;
	for (i=0; i<dat->header->num_entries; i++) {

		int p = (i * DAT_TABLE_ENTRY_BYTES);

		DAT_FileEntry *entry = dat->table[i];
		entry->offset = file_pos;
		memcpy(p+newbuffer, entry, DAT_TABLE_ENTRY_BYTES);

		file_pos += entry->size;
	}

	*buffer = newbuffer;
	return 0;
}

static int dat_write_files(DAT *dat, FILE *out)
{
	int error = 0;
	FILE *in  = NULL;

	char buffer[DAT_RW_BUFFER];
	memset(buffer, 0, DAT_RW_BUFFER);

	int i;
	for (i=0; i<dat->header->num_entries; i++) {
		DAT_FileEntry *entry = dat->table[i];

		in = fopen(entry->fullname, "rb");
		if (in == NULL) {
			#ifdef DAT_DEBUG
				printf("%s: %i\n", __FILE__, __LINE__);
			#endif
			error = -DAT_EFILE;
			goto end_with_error;
		}

		while (!feof(in)) {
			int bytes = fread(buffer, 1, DAT_RW_BUFFER, in);
			if (bytes <= 0) {
				#ifdef DAT_DEBUG
					printf("%s: %i\n", __FILE__, __LINE__);
				#endif
				error =  -DAT_EREAD;
				goto end_with_error;
			}

			if (fwrite(buffer, 1, bytes, out) <= 0) {
				#ifdef DAT_DEBUG
					printf("%s: %i\n", __FILE__, __LINE__);
				#endif
				error = -DAT_EWRITE;
				goto end_with_error;
			} 
		}

		fflush(out);
		fclose(in);
	}

	return 0;

end_with_error:
	if (in) fclose(in);
	return error;
}

int DAT_Write(DAT *dat)
{
	int error = 0;
	FILE *out = NULL;
	
	out = fopen(dat->name, "wb+");
	if (out == NULL) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		error = -DAT_EFILE;
		goto end_with_error;
	}

	/* write magic */
	if (fwrite(dat->magic, 1, DAT_MAGIC_SIZE, out) <= 0) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		error = -DAT_EWRITE;
		goto end_with_error;
	}
	
	/* write header*/
	if (fwrite(dat->header, 1, sizeof(DAT_Header), out) <= 0) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		error = -DAT_EWRITE;
		goto end_with_error;
	}

	/* create table */
	int num_entries_bytes =
		(dat->header->num_entries * DAT_TABLE_ENTRY_BYTES);

	char *table_buffer = NULL; 
	if ((error = dat_create_table(dat, num_entries_bytes,
		&table_buffer, ftell(out))) < 0) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		goto end_with_error;
	}

	/* write table */
	if (fwrite(table_buffer, 1, num_entries_bytes, out) <= 0) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		error = -DAT_EWRITE;
		goto end_with_error;
	}

	/* write files*/
	if (error = dat_write_files(dat, out) < 0) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		goto end_with_error;
	}

	fclose(out);
	free(table_buffer);

	return 0;
end_with_error:
	if (out)          fclose(out);
	if (table_buffer) free(table_buffer);
	return error;	
}

static int dat_seek_file(FILE *dat, long pos)
{
	if (dat == NULL) {
		return -DAT_ENULL;
	}
	
	/*go to the beginning of the file*/
	rewind(dat);

	/*seek to pos*/
	if ((fseek(dat, pos, SEEK_SET)) < 0) {
		return -DAT_ESEEK;
	}
	return 0;
}

int DAT_GetHeaderInfo(char *id, char *version,
	DAT_Sint32 *num_entries, FILE *dat)
{
	int error = 0;
	if ((error = dat_seek_file(dat, DAT_MAGIC_SIZE)) < 0) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		return error;
	}

	/*read the header*/
	DAT_Header header = {0};
	if ((fread(&header, 1, sizeof(DAT_Header), dat)) <= 0) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		return -DAT_EREAD;
	}

	if (id)          memcpy(id, header.id, DAT_ID_SIZE);
	if (version)     memcpy(version, header.version, DAT_VERSION_SIZE);
	if (num_entries) memcpy(num_entries, &header.num_entries, 4);
	
	/*go to the beginning of the file*/
	rewind(dat);

	return 0;
}

int DAT_GetEntryInfo(DAT_Sint32 entry, char *entryname, DAT_Sint32 *size,
	DAT_Sint64 *offset, FILE *dat)
{
	int error = 0;
	if ((error = dat_seek_file(dat, DAT_MAGIC_SIZE + sizeof(DAT_Header) +
		(DAT_TABLE_ENTRY_BYTES * entry))) < 0) {

		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		return error;
	}

	DAT_FileEntry entrydata = {0};
	if ((fread(&entrydata, 1, DAT_TABLE_ENTRY_BYTES, dat)) <= 0) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		return -DAT_EREAD;
	}

	if (entryname) memcpy(entryname, entrydata.name, DAT_NAME_SIZE);
	if (size)      *size   = entrydata.size;
	if (offset)    *offset = entrydata.offset;
	
	/*go to the beginning of the file*/
	rewind(dat);

	return 0;
}

int DAT_GetEntryIndex(char *entryname, DAT_Sint32 *entry, FILE *dat)
{
	int error = 0;
	DAT_Sint32 num_entries = 0;

	if ((error = DAT_GetHeaderInfo(NULL, NULL,
		&num_entries, dat)) < 0) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		return error;
	}

	int i;
	char name[DAT_NAME_SIZE];
	for (i=0; i<num_entries; i++) {
		if ((error = DAT_GetEntryInfo(i, name, NULL,
			NULL, dat)) < 0) {
			#ifdef DAT_DEBUG
				printf("%s: %i\n", __FILE__, __LINE__);
			#endif
			return error;
		}

		if (memcmp(name, entryname, DAT_NAME_SIZE-1) == 0) {
			*entry = i;
			break;
		}		
	}

	return 0;
}

int DAT_GetData(char *buffer, int len, long pos, FILE *dat)
{
	/*go to the beginning of the file*/
	rewind(dat);

	if (fseek(dat, pos, SEEK_SET) < 0) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		return -DAT_ESEEK;
	}

	if (fread(buffer, 1, len, dat) <= 0) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		return -DAT_EREAD;
	}
	
	/*go to the beginning of the file*/
	rewind(dat);

	return 0;
}

int DAT_ParseFilePath(char *path, char **newname)
{
	int error = 0;

	if (path == NULL) {
		#ifdef DAT_DEBUG
			printf("%s: %i\n", __FILE__, __LINE__);
		#endif
		return -DAT_ENULL;
	}

	int len = strlen(path);
	int i, index = -1;

	for (i=0; i< len; i++) {
		if (*(path+i) == DAT_DIR_SEPARATOR)
			index = i;	
	}
	
	*newname = (path+(index+1));
	return 0;
}
