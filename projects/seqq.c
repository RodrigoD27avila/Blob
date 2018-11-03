#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *in = fopen(argv[1], "r");
    if (in == NULL) {
        perror("Unable to open");
        exit(EXIT_FAILURE);
    }

    int countseq = 0;
    int  count = 0;
    unsigned char character = 0;
    unsigned char lastchar  = 0;
    while (fread(&character, 1, 1, in) > 0) {

        if (lastchar == character) {
            count += 1;
        } else {

            if (count >= 1) {
                countseq += 1;
                printf("%4u=%i\n", lastchar, count+1);
            }

            count = 0;
        }

        lastchar = character;
    }
    printf("n seq = %i\n", countseq);
    fclose(in);
    return 0;
}
