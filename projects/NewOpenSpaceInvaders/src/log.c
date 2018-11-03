#include "log.h"
#include "memory.h"

#define LOG_BUFFER_SIZE 512

static FILE *error_out;
static FILE *warning_out;
static FILE *info_out;

static char *CreateBuffer(va_list argp, const char *msg);

void log_Init(FILE *error, FILE *warning, FILE *info)
{
	/* set default*/
	error_out   = error;
	warning_out = warning;
	info_out    = info;

	/* set error output */
	if (error_out == NULL) {
		error_out = stderr;
	}

	/* set warning output */
	if (warning_out == NULL) {
		warning_out = stdout;
	}

	/* set info output */
	if (info_out == NULL) {
		info_out = stdout;
	}
}

void log_Quit()
{
	/* close log outputs */
	fclose(error_out);
	fclose(warning_out);
	fclose(info_out);
}

void log_Error(const char *msg, ...)
{
	/* create va list */
	va_list argp;
	va_start(argp, msg);

	/* create message */
	char *buffer = CreateBuffer(argp, msg);
	fprintf(error_out, "[ERROR]   %s:%d %s\n", __FILE__, __LINE__, buffer);
	fflush(error_out);

	/* free buffer and close va_list */
	memory_Free(buffer);
	va_end(argp);
}

void log_Warning(const char *msg, ...)
{
	/* create va list */
	va_list argp;
	va_start(argp, msg);

	/* create message */
	char *buffer = CreateBuffer(argp, msg);
	fprintf(warning_out, "[WARNING] %s\n", buffer);
	fflush(warning_out);

	/* free buffer and close va_list */
	memory_Free(buffer);
	va_end(argp);
}

void log_Info(const char *msg, ...)
{
	/* create va list */
	va_list argp;
	va_start(argp, msg);

	/* create message */
	char *buffer = CreateBuffer(argp, msg);
	fprintf(info_out, "[INFO]    %s\n", buffer);
	fflush(info_out);

	/* free buffer and close va_list */
	memory_Free(buffer);
	va_end(argp);
}

static char *CreateBuffer(va_list argp, const char *msg)
{
	/* alloc buffer */
	char *buffer = memory_Alloc(LOG_BUFFER_SIZE);

	/* print message to buffer */
	vsnprintf(buffer, LOG_BUFFER_SIZE - 1, msg, argp);

	return buffer;
}
