/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:43:45 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/13 01:16:24 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_table	table;

	if (!parse(argc, (const char **)argv, &table.data))
		return (1);
	if (!set_table(&table))
	{
		clear_table(&table);
		return (1);
	}
	if (start(&table))
		join(&table);
	clear_table(&table);
	return (0);
}

int	start(t_table *table)
{
	size_t	index;

	index = 0;
	while (index < table->data.size)
	{
		table->philos[index].start_time = get_msec();
		table->philos[index].last_eating = get_msec();
		if (pthread_create(&table->philos[index].th, NULL, \
						doing, &table->philos[index]))
			return (0);
		index++;
		usleep(1);
	}
	return (1);
}

void	join(t_table *table)
{
	size_t	index;

	index = 0;
	while (index < table->data.size)
	{
		pthread_join(table->philos[index].th, NULL);
		index++;
	}
}

void	clear_table(t_table *table)
{
	if (table->to_eat)
	{
		pthread_mutex_destroy(table->to_eat);
		free(table->to_eat);
	}
	if (table->to_print)
	{
		pthread_mutex_destroy(table->to_print);
		free(table->to_print);
	}
	if (table->to_check)
	{
		pthread_mutex_destroy(table->to_check);
		free(table->to_check);
	}
	if (table->forks)
		clear_forks(table->forks, table->data.size);
	if (table->philos)
		free(table->philos);
}

void	alloc_mutexes(t_philo *philos, t_mutex *to_print, \
					t_mutex *to_eat, t_mutex *to_check)
{
	size_t	index;

	index = 0;
	while (index < philos[0].data.size)
	{
		philos[index].to_eat = to_eat;
		philos[index].to_print = to_print;
		philos[index].to_check = to_check;
		index++;
	}
}
