#include <stdio.h>

int main()
{
    int n;
    char line[256];
    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "%d", &n)) {
            n = 0;
        }
    }
}
