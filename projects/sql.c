#include <stdio.h>
#include <stdlib.h>

#include <sqlite3.h>

int main(int argc, char **argv)
{
	if (argc <= 1) {
		fprintf(stderr, "USAGE: %s <database>", argv[0]);
		exit(EXIT_FAILURE);
	}	

	const char *dattabase = argv[2];

	sqlite3      *conn;
	sqlite3_stmt *res;
	int          error;
	const char   *tail;

	error = sqlite3_open(dattabase, &conn);
	if (error != SQLITE_OK) {
		fprintf(stderr, "Unable to open database!\n");
		exit(EXIT_FAILURE);
	}

	error = sqlite3_prepare_v2(conn,
		"select * from people order by id",
		1000, &res, &tail);

	if (error != SQLITE_OK) {
		fprintf(stderr, "Unable to get any data!\n");
		exit(EXIT_FAILURE);
	}

	while (sqlite3_step(res) == SQLITE_ROW) {
		printf("%s|", sqlite3_column_text(res, 0));
		printf("%s|", sqlite3_column_text(res, 1));
		printf("%s|", sqlite3_column_text(res, 2));
		printf("%u|", sqlite3_column_int (res, 3));
	}

	sqlite3_finalize(res);
	sqlite3_close(conn);
	return 0;
	
	return 0;
}
