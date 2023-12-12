/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:27:10 by juhyelee          #+#    #+#             */
/*   Updated: 2023/10/04 18:44:09 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <signal.h>

static void	exception(int argc);
static void	send(const pid_t server_pid, char ch);

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*message;

	if (argc == 3 && argv[2][0] != '\0')
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0)
		{
			ft_printf("ERROR: Invalid PID\n");
			exit(1);
		}
		message = argv[2];
		while (*message)
		{
			send(server_pid, *message);
			message++;
		}
	}
	else
		exception(argc);
	return (0);
}

static void	exception(int argc)
{
	if (argc < 3)
		ft_printf("ERROR: Not enough arguments\n");
	else if (argc > 3)
		ft_printf("ERROR: Too many arguments\n");
	else
		ft_printf("ERROR: Invalid arguments\n");
	exit(1);
}

static void	send(const pid_t server_pid, char ch)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < 9)
	{
		if (ch % 2 == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		ch /= 2;
		cnt++;
	}
}
