/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:01:37 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/13 01:40:20 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		is_over(t_thread *thread)
{
	t_time	diff_time;

	pthread_mutex_lock(thread->to_check);
	diff_time = get_msec() - thread->last_eating;
	if (thread->stat != e_eat && diff_time > thread->data.dead)
		return (pthread_mutex_unlock(thread->to_check), 1);
	pthread_mutex_unlock(thread->to_check);
	return (0);
}

void	*check_all_threads(void *arg)
{
	t_table	*table;
	size_t	index;
	size_t	n_dead;

	table = arg;
	n_dead = 0;
	while(n_dead < table->data.size)
	{
		n_dead = 0;
		index = 0;
		while (index < table->data.size)
		{
			if (!is_not_dead(&table->philos[index]))
				n_dead++;
			else if (is_over(&table->philos[index]))
			{
				print_thread(&table->philos[index], "die");
				pthread_mutex_lock(table->to_act);
				table->philos[index].stat = e_dead;
				pthread_mutex_unlock(table->to_act);
				n_dead++;
			}
			index++;
		}
	}
	return (arg);
}

void	wait_msec(t_time time)
{
	const t_time	start_time = get_msec();

	while (get_msec() - start_time < time)
		usleep(200);
}
