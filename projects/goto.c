#include <stdio.h>

void foo();

void foo()
{
    printf("Foo!!\n");
}

int vox();

int vox()
{

    goto vox;
    return 2;
vox:
    
    return 3;

}

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        foo();
        goto end;
    }

    printf("Hello Goto!!\n");

end:
    printf("End.\n");
    return vox();
}
