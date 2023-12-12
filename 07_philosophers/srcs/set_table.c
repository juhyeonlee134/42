/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:19:16 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/13 01:35:12 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		set_table(t_table *table)
{
	table->forks = set_forks(table->data.size);
	if (!table->forks)
		return (0);
	table->to_act = set_mutex();
	if (!table->to_act)
		return (0);
	table->to_print = set_mutex();
	if (!table->to_print)
		return (0);
	table->to_check = set_mutex();
	if (!table->to_check)
		return (0);
	table->philos = set_phlios(table->data, table->forks);
	if (!table->philos)
		return (0);
	alloc_mutexes(table->philos, table->to_print, \
				table->to_act, table->to_check);
	return (1);
}

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

t_philo	*set_phlios(const t_data data, t_fork *forks)
{
	t_philo	*philos;
	size_t	index;

	philos = (t_philo *)malloc(sizeof(t_philo));
	if (!philos)
		return (print_error("malloc failed"), NULL);
	index = 0;
	while (index < data.size)
	{
		philos[index].stat = e_ready;
		philos[index].data = data;
		philos[index].index = index;
		philos[index].cnt = 0;
		alloc_forks(&philos[index], forks);
		index++;
	}
	return (philos);
}
