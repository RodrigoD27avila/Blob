#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char **argv)
{
    int mysocket;
    struct sockaddr_in addr = {0};

    mysocket = socket(AF_INET, SOCK_STREAM, 0);

    if (mysocket == -1)
    {
        fprintf(stderr, "Socket error!!\n");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_port   = htons(1234);
    addr.sin_addr.s_addr = INADDR_ANY;

    memset(&addr.sin_zero, 0, sizeof(addr.sin_zero));

    if (bind(mysocket, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        fprintf(stderr, "Bind error!!\n");
        exit(EXIT_FAILURE);
    }

    if (listen(mysocket, 1) == -1)
    {
        fprintf(stderr, "Listen error!!\n");
        exit(EXIT_FAILURE);
        
    }

    printf("Waiting for connections...\n");
    mysocket = accept(mysocket, 0, 0);

    if (mysocket == -1)
    {
        fprintf(stderr, "Accept error!!\n");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted!!\n");

    close(mysocket);
    
    return 0;
}

