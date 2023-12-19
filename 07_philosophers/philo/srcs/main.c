/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:27:10 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/20 05:54:23 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	if (!parse(argc, (const char **)argv, &table.args))
		return (1);
	if (!init_table(&table))
		return (clear_table(&table), 1);
	if (create_threads(&table))
		join_threads(&table);
	clear_table(&table);
	return (0);
}

void	*check(void *arg)
{
	t_table	*table;

	table = arg;
	while (is_not_dead_one(table) && is_not_over_all(table))
		;
	return (NULL);
}

int	is_not_dead_one(t_table *table)
{
	size_t	index;
	size_t	diff_time;

	index = 0;
	while (index < table->args.num_of_philos)
	{
		pthread_mutex_lock(table->stat_lock);
		diff_time = get_current_time() - table->philos[index].id.last_eating;
		if (!table->philos[index].id.is_end && \
			diff_time > table->args.time_to_die)
		{
			print_stat(&table->philos[index], "die");
			table->dead_flag = 1;
			return (pthread_mutex_unlock(table->stat_lock), 0);
		}
		index++;
		pthread_mutex_unlock(table->stat_lock);
	}
	return (1);
}

int	is_not_over_all(t_table *table)
{
	size_t	index;
	size_t	num_of_end;

	pthread_mutex_lock(table->stat_lock);
	if (table->args.num_of_eating == NO_OPTION)
		return (pthread_mutex_unlock(table->stat_lock), 1);
	index = 0;
	num_of_end = 0;
	while (index < table->args.num_of_philos)
	{
		if (table->philos[index].id.is_end)
			num_of_end++;
		index++;
	}
	if (num_of_end == table->args.num_of_philos)
		return (pthread_mutex_unlock(table->stat_lock), 0);
	return (pthread_mutex_unlock(table->stat_lock), 1);
}

int	is_over(t_philo *philo)
{
	pthread_mutex_lock(philo->locks.stat_lock);
	if (*philo->id.is_dead)
		return (pthread_mutex_unlock(philo->locks.stat_lock), 1);
	if (philo->args.num_of_eating != NO_OPTION && \
		philo->id.cnt_eat >= philo->args.num_of_eating)
	{
		philo->id.is_end = 1;
		return (pthread_mutex_unlock(philo->locks.stat_lock), 1);
	}
	pthread_mutex_unlock(philo->locks.stat_lock);
	return (0);
}
