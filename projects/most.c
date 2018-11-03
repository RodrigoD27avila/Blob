#include <stdio.h>
#include <stdlib.h>

static int table[256];

int main(int argc, char **argv)
{
    FILE *in = fopen(argv[1], "rb");
    if (in == NULL) {
        perror("cannot open file");
        exit(EXIT_FAILURE);
    }

    unsigned char currc, lastc=0;
    unsigned char buffer[8192];
    size_t count = 0;
    int k;
    while ((count = fread(&buffer[0], 1, 8192, in)) > 0) {
        for (k=0; k<count; k++) {
            table[buffer[k]] += 1;
        }
    }

    fclose(in);

    int j;
    for (j=0; j<256; j++) {
         printf("%i|%03u\n",table[j], j);
    }

    return 0;
}
