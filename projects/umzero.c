#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 8192

int main(int argc, char **argv)
{
    FILE *in  = fopen(argv[1], "rb");
    FILE *out = fopen(argv[2], "w+");
    if (in == NULL || out == NULL) {
        perror("cannot open file");
        exit(EXIT_FAILURE);
    }

    unsigned char currc, lastc=0;
    unsigned char buffer[MAX_BUFFER];
    unsigned char onebb[MAX_BUFFER];
    size_t count = 0;
    int k, sum = 1;
    memset(onebb, '1', MAX_BUFFER);
    while ((count = fread(&buffer[0], 1, MAX_BUFFER, in)) > 0) {
        while (sum) {
            sum = 0;
            for (k=0; k<MAX_BUFFER; k+=2) {
                if (onebb[k] && buffer[k] > 0) {
                    buffer[k] -= 1;
                    sum += 1;
                } else {
                    onebb[k] = '0';
               }
            }
            fwrite(&onebb[0], 1, MAX_BUFFER, out);
        }

        sum = 1;
        while (sum) {
            sum = 0;
            for (k=1; k<MAX_BUFFER; k+=2) {
                if (onebb[k] && buffer[k] > 0) {
                    buffer[k] -= 1;
                    sum += 1;
                } else {
                    onebb[k] = '0';
               }
            }
            fwrite(&onebb[0], 1, MAX_BUFFER, out);
        }
    }

    fflush(out);
    fclose(out);
    fclose(in);
    return 0;
}
