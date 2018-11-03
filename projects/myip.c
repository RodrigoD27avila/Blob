#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>

int main(int argc, char **argv)
{
	int fd;
	struct ifreq ifr;
	const char *interface = NULL;

	if (argc < 2) {
		fprintf(stderr, "USAGE: %s <interface>", argv[0]);
		exit(EXIT_FAILURE);
	}

	interface = argv[1];
	fd        = socket(AF_INET, SOCK_DGRAM, 0);
	
	// to get ipv4 address
	ifr.ifr_addr.sa_family = AF_INET;
	strncpy(ifr.ifr_name, interface, IFNAMSIZ-1);

	ioctl(fd, SIOCGIFADDR, &ifr);

	close(fd);

	// result
	struct sockaddr_in *in = (struct sockaddr_in *)&ifr.ifr_addr;
	printf("%s\n", inet_ntoa(in->sin_addr));


	return 0;
}
