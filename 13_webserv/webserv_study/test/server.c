#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

char *get_line(int const fd);
int contain_not_nl(char const *str);
char *merge(char const *r, char const *const buffer);
char *extract(char *const str);

int main(int argc, char *argv[])
{
	int server_sock, client_sock;
	struct sockaddr_in server_addr, client_addr;
	socklen_t client_addr_len;
	char *message;

	puts("start");
	if (argc != 2)
	{
		printf("usage : %s port\n", argv[0]);
		return 1;
	}
	/* socket 생성 */
	if ((server_sock = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket error");
		exit(1);
	}
	puts("socket open");
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(argv[1]));
	/* binding */
	if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
	{
		perror("bind error");
		exit(1);
	}
	puts("binding OK");
	/* listening */
	if (listen(server_sock, 5) < 0)
	{
		perror("listen error");
		exit(1);
	}
	puts("listening...");
	client_addr_len = sizeof(client_addr);
	client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
	if (client_sock < 0)
	{
		perror("accept error");
		exit(1);
	}
	puts("accept");
	message = get_line(client_sock);
	printf("client : %s\n", message);
	free(message);
	close(client_sock);
	close(server_sock);
	return 0;
}

char *get_line(int const fd)
{
	static char *remain;
	char *ret;
	char buffer[1024];
	int buffer_len;

	while (contain_not_nl(remain))
	{
		buffer_len = read(fd, buffer, 1023);
		if (buffer_len <= 0)
			break;
		buffer[buffer_len] = '\0';
		remain = merge(remain, buffer);
	}
	if (!remain)
		return NULL;
	ret = extract(remain);
	return ret;
}

int contain_not_nl(char const *str)
{
	if (!str)
		return 1;
	while (*str)
	{
		if (*str == '\n')
			return 0;
		str++;
	}
	return 1;
}

char *merge(char const *r, char const *const buffer)
{
	char *ret;

	if (!r)
	{
		ret = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
		if (!ret)
			exit(1);
		strcpy(ret, buffer);
	}
	else
	{
		ret = (char *)malloc(sizeof(char) * (strlen(r) + strlen(buffer) + 1));
		if (!ret)
			exit(1);
		strcpy(ret, r);
		strcat(ret, buffer);
	}
	return ret;
}

char *extract(char *const str)
{
	size_t len;
	size_t index;
	char *ret;

	for (len = 0; str[len] && str[len] != '\n'; len++);
	ret = (char *)malloc(sizeof(char) * len);
	if (!ret)
		exit(1);
	strncpy(ret, str, len);
	ret[len] = '\0';
	for (index = 0; str[index + len]; index++)
		str[index] = str[index + len];
	str[index] = '\0';
	return ret;
}
