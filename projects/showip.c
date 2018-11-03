#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define IPV4_SADDR(in) ((struct sockaddr_in *)in->ai_addr)
#define IPV6_SADDR(in) ((struct sockaddr_in6 *)in->ai_addr)

int main(int argc, char **argv)
{
	struct addrinfo hints, *res, *p;
	int status;
	char ipstr[INET6_ADDRSTRLEN];

	if (argc != 2) {
		fprintf(stderr, "USAGE: showip <hostname>\n");
		exit(EXIT_FAILURE);
	}

	memset(&hints, 0, sizeof(hints));
	hints.ai_family   = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	
	status = getaddrinfo(argv[1], NULL, &hints, &res);
	if (status != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
		exit(EXIT_FAILURE);
	}

	printf("IP address for %s:\n\n", argv[1]);

	for (p=res; p != NULL; p = p->ai_next)	{
		void *addr;
		char *ipver;

		if (p->ai_family == AF_INET) {
			struct sockaddr_in *ipv4 = IPV4_SADDR(p);
			addr  = &(ipv4->sin_addr);
			ipver = "IPv4"; 
		}
		else {
			struct sockaddr_in6 *ipv6 = IPV6_SADDR(p);
			addr  = &(ipv6->sin6_addr);
			ipver = "IPv6"; 
		}

		inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
		printf(" %s: %s\n", ipver, ipstr);
	}

	freeaddrinfo(res);

	return 0;
}
