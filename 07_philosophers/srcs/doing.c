/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:43:50 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/13 03:40:22 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *doing(void *arg)
{
	t_thread	*thread;

	thread = arg;
	if (thread->index % 2 == 1)
	{
		print_thread(thread, "is thinking");
		wait_msec(1);
	}
	while (is_not_dead(thread))
	{
		eat(thread);
		print_thread(thread, "is sleeping");
		wait_msec(thread->data.sleeping);
		if (is_not_dead(thread))
			print_thread(thread, "is thinking");
	}
	return (arg);
}

void	eat(t_thread *thread)
{
	pthread_mutex_lock(thread->r);
	print_thread(thread, "has taken a fork");
	if (!thread->l)
	{
		wait_msec(thread->data.dead);
		pthread_mutex_unlock(thread->r);
		return ;
	}
	pthread_mutex_lock(thread->l);
	print_thread(thread, "has taken a fork");
	thread->stat = e_eat;
	print_thread(thread, "is eating");
	wait_msec(thread->data.eating);
	pthread_mutex_lock(thread->to_access);
	thread->cnt++;
	thread->last_eating = get_msec();
	pthread_mutex_unlock(thread->to_access);
	thread->stat = e_ready;
	pthread_mutex_unlock(thread->l);
	pthread_mutex_unlock(thread->r);
}

void	print_thread(t_thread *thread, const char *str)
{
	t_time	diff_time;

	pthread_mutex_lock(thread->to_print);
	diff_time = get_msec() - thread->start_time;
	printf("%llu %zu %s\n", diff_time, thread->index, str);
	pthread_mutex_unlock(thread->to_print);
}

void	alloc_forks(t_philo *philo, t_fork *forks)
{
	if (philo->data.size == 1)
	{
		philo->r = &forks[philo->index];
		philo->l = NULL;
	}
	else if (philo->data.size % 2 == 1 && \
			philo->index + 1 == philo->data.size)
	{
		philo->r = &forks[0];
		philo->l = &forks[philo->index];
	}
	else
	{
		philo->r = &forks[philo->index];
		philo->l = &forks[(philo->index + 1) % philo->data.size];
	}
}

t_time	get_msec(void)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (current.tv_sec * 1000 + current.tv_usec / 1000);
}
