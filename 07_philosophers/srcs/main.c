/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:27:10 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/14 17:38:03 by juhyelee         ###   ########.fr       */
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
	while (check_all_threads(table));
	return (NULL);
}

int	check_all_threads(t_table *table)
{
	size_t	index;
	size_t	diff_time;

	index = 0;
	while (index < table->args.num_of_philos)
	{
		pthread_mutex_lock(table->stat_lock);
		diff_time = get_current_time() - table->philos[index].id.last_eating;
		if (!table->philos[index].id.is_eating && \
				diff_time > table->args.time_to_die)
		{
			print_stat(&table->philos[index], "die");
			table->thread_dead_flag = 1;
			return (pthread_mutex_unlock(table->stat_lock), 0);
		}
		index++;
		pthread_mutex_unlock(table->stat_lock);
	}
	return (1);
}
