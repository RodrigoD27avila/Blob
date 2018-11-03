#include <stdio.h>

#define MASK_0 0
#define MASK_1 1 << 1
#define MASK_2 1 << 2
#define MASK_3 1 << 3
#define MASK_4 1 << 4
#define MASK_5 1 << 5

struct mask
{
    int a:1, b:1, c:1, d:1, e:1;
};

int main()
{
    struct mask j = {1,1,1,1,1};
    int i = MASK_1 | MASK_3 | MASK_5 | MASK_2;
    if (i & MASK_1)
        printf("MASK_1\n");
    if (i & MASK_2)
        printf("MASK_2\n");
    if (i & MASK_3)
        printf("MASK_3\n");
    if (i & MASK_4)
        printf("MASK_4\n");
    if (i & MASK_5)
        printf("MASK_5\n");
    if (i & MASK_0)
        printf("MASK_0\n");

    ((int)j) & MASK_1;
    return 0;
}
