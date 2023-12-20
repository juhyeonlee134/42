/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:59:39 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/20 16:36:06 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_table(t_table *table)
{
	table->dead_flag = 0;
	if (!init_locks(table))
		return (0);
	if (!init_forks(table))
		return (0);
	if (!init_philos(table))
		return (0);
	return (1);
}

int	init_locks(t_table *table)
{
	table->stat_lock = (t_mutex *)malloc(sizeof(t_mutex));
	if (!table->stat_lock)
		return (print_error("malloc failed"), 0);
	if (pthread_mutex_init(table->stat_lock, NULL))
		return (print_error("init mutex failed"), 0);
	table->writing_lock = (t_mutex *)malloc(sizeof(t_mutex));
	if (!table->writing_lock)
		return (print_error("malloc failed"), 0);
	if (pthread_mutex_init(table->writing_lock, NULL))
		return (print_error("init mutex failed"), 0);
	return (1);
}

int	init_forks(t_table *table)
{
	size_t	index;

	table->forks = \
		(t_fork *)malloc(sizeof(t_fork) * table->args.num_of_philos);
	if (!table->forks)
		return (print_error("malloc failed"), 0);
	index = 0;
	while (index < table->args.num_of_philos)
	{
		if (pthread_mutex_init(&table->forks[index], NULL))
		{
			clear_forks(table->forks, index + 1);
			return (print_error("init mutex failed"), 0);
		}
		index++;
	}
	return (1);
}

int	init_philos(t_table *table)
{
	size_t	index;

	table->philos = \
		(t_philo *)malloc(sizeof(t_philo) * table->args.num_of_philos);
	if (!table->philos)
		return (print_error("malloc failed"), 0);
	index = 0;
	while (index < table->args.num_of_philos)
	{
		table->philos[index].args = table->args;
		table->philos[index].id.number = index + 1;
		table->philos[index].id.cnt_eat = 0;
		table->philos[index].id.is_end = 0;
		table->philos[index].id.is_dead = &table->dead_flag;
		table->philos[index].id.start_time = get_current_time();
		table->philos[index].id.last_eating = get_current_time();
		alloc_forks(table, index);
		table->philos[index].locks.stat_lock = table->stat_lock;
		table->philos[index].locks.writing_lock = table->writing_lock;
		index++;
	}
	return (1);
}

void	alloc_forks(t_table *table, const size_t index)
{
	if (table->args.num_of_philos == 1)
	{
		table->philos[0].locks.right_fork = &table->forks[0];
		table->philos[0].locks.left_fork = NULL;
	}
	else if (table->args.num_of_philos % 2 == 1 && \
			index + 1 == table->args.num_of_philos)
	{
		table->philos[index].locks.right_fork = &table->forks[0];
		table->philos[index].locks.left_fork = &table->forks[index];
	}
	else
	{
		table->philos[index].locks.right_fork = &table->forks[index];
		table->philos[index].locks.left_fork = \
			&table->forks[(index + 1) % table->args.num_of_philos];
	}
}
