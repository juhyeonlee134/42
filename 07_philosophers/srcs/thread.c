/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:58:11 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/14 18:40:54 by juhyelee         ###   ########.fr       */
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
	if (!take_right_fork(philo))
		return ;
	if (!take_left_fork(philo))
		return ;
	print_stat(philo, "is eating");
	pthread_mutex_lock(philo->locks.stat_lock);
	philo->id.stat = e_eat;
	philo->id.last_eating = get_current_time();
	pthread_mutex_unlock(philo->locks.stat_lock);
	wait_msec(philo->args.time_to_eat);
	pthread_mutex_lock(philo->locks.stat_lock);
	philo->id.stat = e_ready;
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

int	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->locks.right_fork);
	if (is_over(philo))
		return (pthread_mutex_unlock(philo->locks.right_fork), 0);
	print_stat(philo, "has taken a fork");
	return (1);
}

int	take_left_fork(t_philo *philo)
{
	if (!philo->locks.left_fork)
	{
		pthread_mutex_unlock(philo->locks.right_fork);
		wait_msec(philo->args.time_to_die + 1);
		return (0);
	}
	pthread_mutex_lock(philo->locks.left_fork);
	if (is_over(philo))
		return (pthread_mutex_unlock(philo->locks.right_fork), 0);
	print_stat(philo, "has taken a fork");
	return (1);
}
