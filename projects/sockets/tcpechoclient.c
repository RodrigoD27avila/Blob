#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_ECHO_PORT 7
#define BUFSIZE 1024

static void die_message(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    if (argc < 3 || argc > 4)
        die_message("USAGE: <Server Adress> <Echo Word> [<Server Port>]");

    char *servip  = argv[1];
    char *echostr = argv[2];

    in_port_t servport = (argc == 4) ? atoi(argv[3]) : DEFAULT_ECHO_PORT; 

    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (socket < 0)
        die_message("ERROR: socket() failed.");

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(struct sockaddr_in));
    servaddr.sin_family = AF_INET;

    int retval = inet_pton(AF_INET, servip, &servaddr.sin_addr.s_addr);

    if (retval == 0)
       die_message("ERROR: inet_pton() failed.\nInvalid address.");
    else if (retval < 0)
        die_message("ERROR: inet_pton() failed.");

    servaddr.sin_port = htons(servport);

    if (connect(sock, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
        die_message("ERROR: connect() failed.");

    size_t echostrlen = strlen(echostr);

    ssize_t numbytes = send(sock, echostr, echostrlen, 0);

    if (numbytes < 0)
        die_message("send() failed.");

    else if (numbytes != echostrlen)
        die_message("send(), send unexpected number of bytes.");

    unsigned int totalbytesrec = 0;
    fputs("Received:", stdout);

    while (totalbytesrec < echostrlen)
    {
        char buffer[BUFSIZE];
        numbytes = recv(sock, buffer, BUFSIZE -1, 0);

        if (numbytes < 0)
            die_message("recv() failed.");

        else if (numbytes == 0)
            die_message("recv(), connection closed prematurely.");

        totalbytesrec += numbytes;
        buffer[numbytes] = '\0';
        fputs(buffer, stdout);
    }

    fputc('\n', stdout);
    close(sock);

    return 0;     
}
