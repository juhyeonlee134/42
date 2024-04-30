#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int server_sock;
	struct sockaddr_in server_addr;
	char message[1024];

	if (argc != 3)
	{
		printf("usage : %s address port\n", argv[0]);
		return 1;
	}
	/* socket 생성 */
	if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket error");
		exit(1);
	}
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	server_addr.sin_port = htons(atoi(argv[2]));
	connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
	printf("message : ");
	scanf("%s", message);
	write(server_sock, message, strlen(message));
	close(server_sock);
	return 0;
}