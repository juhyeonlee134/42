#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <string.h>
#include <stdio.h>

#define EPOLL_SIZE 20
#define MAXLINE 1024

struct udata
{
	int fd;
	char name[80];
};

int user_fds[1024];
// 다른 클라이언트에게 전송
void send_msg(struct epoll_event ev, char *msg)
{
	int i;
	char buf[MAXLINE + 24];
	struct udata* user_data = ev.data.ptr;

	for (int i = 0; i < 1024; i++)
	{
		memset(buf, 0x00, MAXLINE + 24);
		sprintf(buf, "%s : %s\n", user_data->name, msg);
		if ((user_fds[i] == 1))
		{
			write(i, buf, MAXLINE + 24);
		}
	}
}

int main(int argc, char **argv)
{
	struct sockaddr_in addr, client_addr;
	struct epoll_event *events;
	struct epoll_event ev;
	struct udata *user_data;

	int epoll_fd, listen_fd, client_fd;
	int addr_len, client_addr_len;
	int n_event, n_read;
	char buf[MAXLINE];

	if (argc != 2)
	{
		printf("usage : %s port\n", argv[0]);
		return 1;
	}
	// epoll 생성
	events = (struct epoll_event *)malloc(sizeof(struct epoll_event) * EPOLL_SIZE);
	if ((epoll_fd = epoll_create(100)) < 0)
	{
		perror("epoll error");
		exit(1);
	}
	// socket 전처리
	addr_len = sizeof(addr);
	if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket error");
		exit(1);
	}
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[1]));
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(listen_fd, (struct sockaddr *)&addr, addr_len) < 0)
	{
		perror("bind error");
		exit(1);
	}
	if (listen(listen_fd, 5) < 0)
	{
		perror("listen error");
		exit(1);
	}
	// event 추가
	ev.events = EPOLLIN; // 데이터를 읽을 수 있으면 이벤트 발생
	ev.data.fd = listen_fd;
	epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &ev);

	memset(user_fds, -1, sizeof(-1) * 1024);
	while (1)
	{
		n_event = epoll_wait(epoll_fd, events, EPOLL_SIZE, -1);
		if (n_event < 0)
		{
			perror("epoll_wait fail");
			exit(1);
		}
		for (int i = 0; i < n_event; i++)
		{
			// 읽기 이벤트가 발생하면...
			if (events[i].data.fd == listen_fd)
			{
				// 연결
				memset(buf, 0x00, MAXLINE);
				client_addr_len = sizeof(client_addr);
				client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr_len);
				user_fds[client_fd] = 1; // 연결 됨을 표시
				// 사용자 입력 데이터를 대기
				user_data = malloc(sizeof(user_data));
				user_data->fd = client_fd;
				char *tmp = "First insert your nickname";
				write(user_data->fd, tmp, 20);
				sleep(1);
				// 사용자 입력을 출력
				read(user_data->fd, user_data->name, sizeof(user_data->name));
				user_data->name[strlen(user_data->name) - 1] = 0;
				printf("!!! Welcome [%s] !!!\n", user_data->name);
				sleep(1);
				// 사용자 입력을 전달
				sprintf(buf, "Okay your nickname : %s\n", user_data->name);
				write(user_data->fd, buf, 40);
				ev.events = EPOLLIN;
				ev.data.ptr = user_data;
				epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &ev);
			}
			else
			{
				user_data = events[i].data.ptr;
				memset(buf, 0x00, MAXLINE);
				n_read = read(user_data->fd, buf, MAXLINE);
				if (n_read <= 0)
				{
					epoll_ctl(epoll_fd, EPOLL_CTL_DEL, user_data->fd, events);
					close(user_data->fd);
					user_fds[user_data->fd] = -1;
					free(user_data);
				}
				else
				{
					send_msg(events[i], buf);
				}
			}
		}
	}
	return 0;
}