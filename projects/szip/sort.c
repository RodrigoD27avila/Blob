#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_BYTES (8*1024)
#define TABLE_SIZE   256

typedef unsigned long long int u64;
typedef unsigned char          u8;

static u8  *buffer;
static u64 *table;

static FILE *in;
static FILE *out;

static void cleanup();
static void init_buffer();
static void init_table();
static void open_files(const char *fin, const char *fout);

static void init_buffer()
{
	buffer = malloc(BUFFER_BYTES);
	if (buffer == NULL) {
		fprintf(stderr, "Unable to initialize buffer.");
		exit(EXIT_FAILURE);
	}

	// zero buffer
	memset(buffer, 0, BUFFER_BYTES);
}

static void init_table()
{
	table = malloc(TABLE_SIZE * sizeof(u64));
	if (table == NULL) {
		fprintf(stderr, "Unable to initialize table.");
		exit(EXIT_FAILURE);
	}

	// zero table
	memset(table, 0, TABLE_SIZE * sizeof(u64));
}

static void open_files(const char *fin, const char *fout)
{
	in = fopen(fin, "rb");
	if (in == NULL) {
		fprintf(stderr, "Unable to open input file.\n");
		goto error;
	}
	
	out = fopen(fout, "wb+");
	if (out == NULL) {
		fprintf(stderr, "Unable to open output file.\n");
		goto error;
	}

	return;

error:
	if (in)  fclose(in);
	if (out) fclose(out);
	cleanup();
	exit(EXIT_FAILURE);
}

static void cleanup()
{
	free(buffer);
	free(table);
}

static inline void transform(size_t bytes)
{
	size_t i, j;
	for (i=0; i< bytes; i++) {
		size_t value = ((u8)buffer[i]) + 1;
		for (j=0; j<value; j++) {
			table[j] += 1;
		}
	}

	// zero buffer
	memset(buffer, 0, BUFFER_BYTES);
}

static void write()
{
	if (fwrite(table, 1, TABLE_SIZE * sizeof(u64), out) < 0) {
		fprintf(stderr, "Unable to write table to output.\n");
		cleanup();
		exit(EXIT_FAILURE);
	}

	// flush out
	fflush(out);
}

int main(int argc, char **argv)
{
	if (argc <= 1 || argc > 3) {
		printf("USAGE: %s <input> <output>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// initialize table
	init_table();

	// initialize buffer
	init_buffer();

	// open files
	open_files(argv[1], argv[2]);

	size_t bytes;
	while ((bytes = fread(buffer, 1, BUFFER_BYTES, in)) > 0) {
		transform(bytes);
	}

	if (bytes < 0) {
		fprintf(stderr, "Unable to read input.\n");
		cleanup();
		exit(EXIT_FAILURE);
	}

	// write table to out
	write();


	// cleanup
	cleanup();
	
	return 0;
}
