/*See Copyright Notice in dat.h*/

#include "datfile.h"
#include "daterror.h"

int DAT_GetFileSize(DAT_Sint32 *size, char *filename)
{
	if (filename == NULL) {
		return -DAT_ENULL;
	}

#if defined DAT_OS_WINDOWS

	static BOOL               file_ok;
	WIN32_FILE_ATTRIBUTE_DATA file_info;

	file_ok = GetFileAttributesEx(TEXT(filename),
		GetFileExInfoStandard, (void *)&file_info);

	if (!file_ok) {
		return -DAT_EFILE;
	}

	*size = file_info.nFileSizeLow;
#elif defined DAT_OS_POSIX

	struct stat file_status;
	
	if (stat(filename, &file_status) < 0) {
		return -DAT_EFILE;
	}

	*size = file_status.st_size;
#endif	

	return 0;
}
