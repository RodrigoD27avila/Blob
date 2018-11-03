#ifdef DEBUG 
#include <stdio.h>
int i = 0;
#endif

int main(int argc, char **argv)
{
    float f;
    for(f=0.0; f < 10.0; f+=0.0000001)
    {
#ifdef DEBUG
        printf("%f\n", f);
        i+=1;            
#endif
    }

#ifdef DEBUG
    printf("%i\n", i);
#endif
    return 0;
}
