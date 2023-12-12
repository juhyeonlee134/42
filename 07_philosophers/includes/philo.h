/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:28:24 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/13 01:05:59 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef unsigned long long	t_time;
typedef pthread_mutex_t		t_mutex;
typedef t_mutex				t_fork;
typedef enum e_stat
{
	e_ready,
	e_eat,
	e_dead
}t_stat;
typedef struct s_data
{
	size_t	size;
	size_t	cnt;
	size_t	dead;
	size_t	eating;
	size_t	sleeping;
}t_data;
typedef struct s_thread
{
	pthread_t	th;
	t_fork		*r;
	t_fork		*l;
	t_mutex		*to_eat;
	t_mutex		*to_print;
	t_mutex		*to_check;
	t_stat		stat;
	t_data		data;
	t_time		start_time;
	t_time		last_eating;
	size_t		index;
	size_t		cnt;
}t_thread;
typedef t_thread	t_philo;
typedef struct s_table
{
	t_philo		*philos;
	t_fork		*forks;
	t_mutex		*to_eat;
	t_mutex		*to_check;
	t_mutex		*to_print;
	t_data		data;
	pthread_t	checker;
}t_table;

int		parse(const size_t argc, const char *argv[], t_data *data);
int		is_invalid(const t_data);
void	print_error(const char *message);
size_t	convert_to_num(const char *str);

int		set_table(t_table *table);
t_fork	*set_forks(const size_t size);
t_mutex	*set_mutex(void);
void	clear_forks(t_fork *forks, const size_t size);
void	alloc_mutexes(t_philo *philos, t_mutex *to_print, \
					t_mutex *to_eat, t_mutex *to_check);
void	alloc_forks(t_philo *philo, t_fork *forks);
t_philo	*set_phlios(const t_data data, t_fork *forks);

int		start(t_table *table);
void	join(t_table *table);
void	clear_table(t_table *table);

int		is_not_dead(t_thread *thread);
void	*doing(void *arg);
void	eat(t_thread *thread);
void	print_thread(t_thread *thread, const char *str);

void	wait_msec(t_time time);
t_time	get_msec(void);

#endif
