/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:19:16 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/12 23:24:27 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutex.h"

t_fork	*set_forks(const size_t size)
{
	t_fork	*forks;
	size_t	index;

	forks = (t_fork *)malloc(sizeof(t_fork) * size);
	if (!forks)
		return (print_error("malloc failed"), NULL);
	index = 0;
	while (index < size)
	{
		if (pthread_mutex_init(&forks[index], NULL))
		{
			clear_forks(forks, index + 1);
			return (print_error("init forks failed"), NULL);
		}
		index++;
	}
	return (forks);
}

t_mutex	*set_mutex(void)
{
	t_mutex	*mutex;

	mutex = (t_mutex *)malloc(sizeof(t_mutex));
	if (!mutex)
		return (print_error("malloc failed"), NULL);
	if (pthread_mutex_init(mutex, NULL))
	{
		free(mutex);
		return (print_error("init forks failed"), NULL);
	}
	return (mutex);
}

void	clear_forks(t_fork *forks, const size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		pthread_mutex_destroy(&forks[index]);
		index++;
	}
	free(forks);
}
