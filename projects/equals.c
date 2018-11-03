#include <stdio.h>
#include <stdlib.h>

#define MAX_READ 8192
static int table[MAX_READ];

int main(int argc, char **argv)
{
    FILE *in = fopen(argv[1], "rb");
    if (in == NULL) {
        perror("cannot open file");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[8192];
    size_t count = 0;
    int i;
    if ((count = fread(&buffer[0], 1, 8192, in)) > 0) {
        table[0] = buffer[0];
        for (i=1; i< count; i++) {
            table[i] = table[i-1]+buffer[i];
        }
    }

    fclose(in);

    for (i=0; i<count; i++) {
           printf("%i\n",table[i]);
    }

    return 0;
}
