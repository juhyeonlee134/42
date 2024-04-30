#include <sys/times.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int client_socket_fd;
	struct sockaddr_in client_addr;
	int data = 0x1234567;
	int client_len;

	client_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	client_addr.sin_port = htons(atoi(argv[1]));
	client_len = sizeof(client_addr);
	if (connect(client_socket_fd, (struct sockadd *)&client_addr, client_len) < 0)
	{
		perror("Connect error : ");
		exit(0);
	}
	data = htonl(data);
	write(client_socket_fd, (void *)&data, sizeof(int));
	read(client_socket_fd, (void *)&data, sizeof(int));
	data = ntohl(data);
	close(client_socket_fd);
	return 0;
}