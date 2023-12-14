/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:43:37 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/14 18:32:10 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	create_threads(t_table *table)
{
	size_t	index;

	index = 0;
	while (index < table->args.num_of_philos)
	{
		if (pthread_create(&table->philos[index].thread, NULL, \
							act, &table->philos[index]))
			return (0);
		index++;
	}
	if (pthread_create(&table->checker, NULL, check, table))
		return (0);
	return (1);
}

void	join_threads(t_table *table)
{
	size_t	index;

	index = 0;
	while (index < table->args.num_of_philos)
	{
		pthread_join(table->philos[index].thread, NULL);
		index++;
	}
	pthread_join(table->checker, NULL);
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

void	clear_table(t_table *table)
{
	pthread_mutex_destroy(table->stat_lock);
	free(table->stat_lock);
	pthread_mutex_destroy(table->writing_lock);
	free(table->writing_lock);
	clear_forks(table->forks, table->args.num_of_philos);
	free(table->philos);
}
