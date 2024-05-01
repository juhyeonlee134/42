#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char **argv)
{
	int socket_fd, socket_len;
	struct sockaddr_in sock_addr;
	fd_set read_fds, old_fds;
	int max_fd, n_fd, n_read, n_write;
	char buf[MAXLINE];

	if (argc  !=3)
	{
		printf("usage : %s address prot\n", argv[0]);
		return 1;
	}
	if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket error");
		exit(1);
	}
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_port = htons(atoi(argv[2]));
	sock_addr.sin_addr.s_addr = inet_addr(argv[1]);
	socket_len = sizeof(sock_addr);
	if (connect(socket_fd, (struct sockaddr *)&sock_addr, socket_len) < 0)
	{
		perror("connect error");
		exit(1);
	}
	FD_ZERO(&read_fds);
	FD_SET(socket_fd, &read_fds);
	FD_SET(0, &read_fds);
	max_fd = socket_fd;
	old_fds = read_fds;
	while (1)
	{
		read_fds = old_fds;
		n_fd = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
		if (FD_ISSET(socket_fd, &read_fds))
		{
			memset(buf, 0x00, MAXLINE);
			n_read = read(socket_fd, buf, MAXLINE);
			if (n_read <= 0)
			{
				perror("read error");
				exit(1);
			}
			n_write = write(1, buf, n_read);
			if (n_write != n_read)
			{
				perror("write error");
				exit(1);
			}
		}
		if (FD_ISSET(0, &read_fds))
		{
			memset(buf, 0x00, MAXLINE);
			n_read = read(0, buf, MAXLINE);
			printf("> %s\n", buf);
			if (n_read <= 0)
			{
				perror("read error");
				exit(1);
			}
			n_write = write(socket_fd, buf, n_read);
			if (n_write != n_read)
			{
				perror("write error");
				exit(1);
			}
		}
	}
	return 0;
}