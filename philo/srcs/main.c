/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:27:10 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/14 00:59:53 by juhyelee         ###   ########.fr       */
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
	size_t	num_of_dead;

	table = arg;
	num_of_dead = 0;
	while (num_of_dead < table->args.num_of_philos)
	{
		num_of_dead = 0;
		check_all_threads(table, &num_of_dead);
	}
	return (NULL);
}

void	check_all_threads(t_table *table, size_t *num_of_dead)
{
	size_t	index;
	size_t	diff_time;

	index = 0;
	while (index < table->args.num_of_philos)
	{
		pthread_mutex_lock(table->stat_lock);
		diff_time = get_current_time() - table->philos[index].id.last_eating;
		if (table->philos[index].id.stat == e_dead)
			(*num_of_dead)++;
		else if (table->philos[index].id.stat != e_eat && \
				diff_time > table->args.time_to_die)
		{
			print_stat(&table->philos[index], "die");
			table->philos[index].id.stat = e_dead;
			//pthread_detach(table->philos[index].thread);
			(*num_of_dead)++;
		}
		index++;
		pthread_mutex_unlock(table->stat_lock);
	}
}
