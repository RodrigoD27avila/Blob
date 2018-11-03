#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *in  = fopen(argv[1], "r");
	FILE *out = fopen(argv[2], "w+");

	static char buffer[20];
	static char newstr[20];
	static int  count;


	while ((fgets(buffer, 19, in)) != NULL) {

		int len = strlen(buffer);
		memcpy(newstr, buffer, len -1);

		if ((count % 8) == 0) {
			fprintf(out, "\n\t");
		}

		fprintf(out, "%7s, ", newstr);
		count += 1;	
		
		memset(newstr, 0, 20);
		memset(buffer, 0, 20);
	}

	fclose(in);
	fflush(out);
	fclose(out);

	return 0;
        
}
