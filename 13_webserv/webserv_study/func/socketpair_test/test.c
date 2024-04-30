#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int sv[2];
	int pid;
	int n = 1;

	if (socketpair(AF_UNIX, SOCK_STREAM, 0, sv) < 0)
	{
		perror("socketpair error");
		exit(0);
	}
	if ((pid = fork()) < 0)
	{
		perror("fork error");
		exit(0);
	}
	if (pid == 0)
	{
		dup2(sv[0], 0);
		close(sv[1]);
		close(sv[0]);
		execl("/home/debian/test", "test", 0);
	}
	close(sv[0]);
	while (1)
	{
		write(sv[1], (void *)&n, sizeof(n));
		sleep(1);
		read(sv[1], (void *)&n, sizeof(n));
		printf("n : %d\n", n);
	}
	return 0;
}
