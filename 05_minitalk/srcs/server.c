/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:39:55 by juhyelee          #+#    #+#             */
/*   Updated: 2023/10/04 18:44:40 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static void	catch(int signo);

int	main(int argc, char *argv[])
{
	struct sigaction	sig;

	if (argc == 1)
	{
		sig.sa_flags = 0;
		sig.sa_handler = catch;
		sigemptyset(&sig.sa_mask);
		if (sigaction(SIGUSR1, &sig, NULL) == -1)
			return (1);
		if (sigaction(SIGUSR2, &sig, NULL) == -1)
			return (1);
		ft_printf("Server PID: %d\n", getpid());
		while (argv[0])
		{
		}
	}
	else
	{
		ft_printf("ERROR: Too many arguments\n");
		exit(1);
	}
	return (0);
}

static void	catch(int signo)
{
	static int		ch;
	static size_t	cnt;

	if (cnt == 8)
	{
		write(0, &ch, 1);
		ch = 0;
		cnt = 0;
	}
	else
	{
		if (signo == SIGUSR2)
			ch |= 1 << cnt;
		cnt++;
	}
}
