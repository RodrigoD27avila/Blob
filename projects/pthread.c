#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message(void *data)
{
    printf("%s\n", (char*)data);
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t t1, t2;
    char *msg1 = "Fuuuuuuuu!!";
    char *msg2 = "Ckkkkkkkk!!";
    int ret1, ret2;

    ret1 = pthread_create(&t1, NULL, print_message, (void*)msg1);
    ret2 = pthread_create(&t2, NULL, print_message, (void*)msg2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("t1 returns: %i\n", ret1);
    printf("t2 returns: %i\n", ret2);
    return 0;
}
