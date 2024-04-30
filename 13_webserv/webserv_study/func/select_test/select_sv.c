#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

#define FD_SIZE 3
#define BUF_SIZE 8

int main(int argc, char *argv[])
{
	int ret, fd_count, end_count = 0;
	int fds[FD_SIZE];
	char buf[BUF_SIZE] = {0, };

	struct timeval tv;
	fd_set retfds, readfds;

	if (argc != 4)
	{
		printf("usage : %s file1 file2 file3\n", argv[0]);
		return 0;
	}

	// readfds 초기화
	FD_ZERO(&readfds);
	for (int i = 0; i < FD_SIZE; i++)
	{
		fds[i] = open(argv[i + 1], O_RDONLY);
		if (fds[i]  >= 0)
		{
			FD_SET(fds[i], &readfds);
			fd_count = fds[i]; // fd_count는 3개의 파일을 열었으니까. 3, 4, 5가 될 것
		}
	}

	// 감시(검사)
	while (1)
	{
		// 원본 유지
		retfds = readfds;
		// fd_count가 5이니, 6까지 검사
		if (select(fd_count + 1, &retfds, NULL, NULL, NULL) < 0)
		{
			perror("select error ");
			exit(0);
		}
		for (int i = 0; i < FD_SIZE; i++)
		{
			// 만일 검사하는 것으로 되어 있다면...
			if (FD_ISSET(fds[i], &retfds))
			{
				// 파일을 모두 읽어온다.
				while (read(fds[i], buf, BUF_SIZE) > 0)
				{
					// 파일 읽기 종료 조건
					if (!strcmp(buf, "quit\n"))
					{
						// 다 읽은 파일에 대해서 더이상 검사하지 않음
						FD_CLR(fds[i], &readfds);
						close(fds[i]);
						end_count++;
						if (end_count == FD_SIZE)
							exit(0);
						continue;
					}
					printf("fd[%d] - %s", fds[i], buf);
					memset(buf, 0x00, BUF_SIZE);
				}
			}
		}
	}
	return 0;
}