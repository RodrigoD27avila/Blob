#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PENDING 5
#define BUFSIZE 1024

static void die_message(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

static void handle_tcp_client(int clisock)
{
    char buffer[BUFSIZE];
    
    ssize_t numbytesrec = recv(clisock, buffer, BUFSIZE, 0);
    if (numbytesrec < 0)
        die_message("recv() failed.");
    

    while (numbytesrec > 0)
    {
       ssize_t numbytessend = send(clisock, buffer, numbytesrec, 0);
    
        if (numbytessend < 0)
            die_message("send() failed.");

        else if (numbytessend != numbytesrec)
            die_message("send(), sent unexpeted number of bytes.");

        numbytesrec = recv(clisock, buffer, BUFSIZE, 0);
        if (numbytesrec < 0)
            die_message("recv() failed.");
    }

    close(clisock);
    
}

int main(int argc, char **argv)
{
    if (argc != 2)
        die_message("USAGE: <Server Port>");
    
    in_port_t servport = atoi(argv[1]);
    
    int servsock;
    if ((servsock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        die_message("socket() failed.");

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(struct sockaddr_in));

    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port        = htons(servport);

    if ((bind(servsock, (struct sockaddr *) &servaddr, sizeof(servaddr))) < 0)
        die_message("bind() failed.");

    if ((listen(servsock, MAX_PENDING) < 0))
        die_message("listen() failed.");

    for (;;)
    {
        struct sockaddr_in cliaddr;
        socklen_t cliaddrlen = sizeof(struct sockaddr_in);

        int clisock = accept(servsock, (struct sockaddr *) &cliaddr,
                &cliaddrlen);

        if (clisock < 0)
            die_message("accept() failed.");

        char cliname[INET_ADDRSTRLEN];
        if ((inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, cliname,
                sizeof(cliname)) != NULL))
        {
            printf("s_addr = %u\n", cliaddr.sin_addr.s_addr);
            printf("Handling client %s/%d.\n",
                cliname, ntohs(cliaddr.sin_port));
        }

        else
            fputs("Unable to get client address.\n", stdout);

        handle_tcp_client(clisock);
    } 
    
    return 0;
}
