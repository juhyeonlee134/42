/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:58:11 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/14 17:34:53 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*act(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id.number % 2 == 1)
	{
		print_stat(philo, "is thinking");
		wait_msec(1);
	}
	while (!is_over(philo))
	{
		eat(philo);
		if (is_over(philo))
			break ;
		print_stat(philo, "is sleeping");
		wait_msec(philo->args.time_to_sleep);
		if (is_over(philo))
			break ;
		print_stat(philo, "is thinking");
	}
	return (NULL);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->locks.right_fork);
	if (is_over(philo))
		return ;
	print_stat(philo, "has taken a fork");
	if (!philo->locks.left_fork)
	{
		pthread_mutex_unlock(philo->locks.right_fork);
		wait_msec(philo->args.time_to_die + 1);
		return ;
	}
	pthread_mutex_lock(philo->locks.left_fork);
	print_stat(philo, "has taken a fork");
	print_stat(philo, "is eating");
	pthread_mutex_lock(philo->locks.stat_lock);
	philo->id.is_eating = 1;
	philo->id.last_eating = get_current_time();
	pthread_mutex_unlock(philo->locks.stat_lock);
	wait_msec(philo->args.time_to_eat);
	pthread_mutex_lock(philo->locks.stat_lock);
	philo->id.is_eating = 0;
	philo->id.cnt_eat++;
	pthread_mutex_unlock(philo->locks.stat_lock);
	pthread_mutex_unlock(philo->locks.left_fork);
	pthread_mutex_unlock(philo->locks.right_fork);
}

void	print_stat(t_philo *philo, const char *message)
{
	size_t	diff_time;

	pthread_mutex_lock(philo->locks.writing_lock);
	diff_time = get_current_time() - philo->id.start_time;
	printf("%zu %zu %s\n", diff_time, philo->id.number + 1, message);
	pthread_mutex_unlock(philo->locks.writing_lock);
}

int	is_over(t_philo *philo)
{
	pthread_mutex_lock(philo->locks.stat_lock);
	if (*philo->id.is_dead || (philo->args.num_of_eating != -2 && \
		philo->id.cnt_eat >= philo->args.num_of_eating))
		return (pthread_mutex_unlock(philo->locks.stat_lock), 1);
	pthread_mutex_unlock(philo->locks.stat_lock);
	return (0);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->locks.stat_lock);
	if (*philo->id.is_dead)
		return (pthread_mutex_unlock(philo->locks.stat_lock), 1);
	pthread_mutex_unlock(philo->locks.stat_lock);
	return (0);
}
