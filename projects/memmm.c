#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *nome = malloc(7 * sizeof(char));

    memset(nome, 0, 7);
    memset(nome, 'Z', 4);

    //char c = 'R';
    //memcpy(nome, &c, 1);

    printf("%s\n", nome);

    free(nome);
    return 0;
}

