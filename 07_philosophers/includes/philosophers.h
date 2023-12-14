/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:01:10 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/14 17:36:56 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define INCORRECT (size_t)-1
# define NO_OPTION -2

typedef __int128_t		t_long;
typedef __uint128_t		t_time;
typedef pthread_mutex_t	t_mutex;
typedef t_mutex			t_fork;
typedef pthread_t		t_thread;

typedef struct s_arguments
{
	size_t	num_of_philos;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	t_long	num_of_eating;
}t_arguments;

typedef struct s_locks
{
	t_fork	*left_fork;
	t_fork	*right_fork;
	t_mutex	*stat_lock;
	t_mutex	*writing_lock;
}t_locks;

typedef struct s_identifier
{
	int			is_eating;
	int			*is_dead;
	size_t		number;
	t_long		cnt_eat;
	t_time		start_time;
	t_time		last_eating;
}t_identifier;

typedef struct s_philo
{
	t_thread		thread;
	t_locks			locks;
	t_identifier	id;
	t_arguments		args;
}t_philo;

typedef struct s_table
{
	int			thread_dead_flag;
	t_philo		*philos;
	t_fork		*forks;
	t_mutex		*stat_lock;
	t_mutex		*writing_lock;
	t_arguments	args;
	t_thread	checker;
}t_table;

int		parse(const size_t argc, const char *argv[], t_arguments *args);
t_long	convert_to_number(const char *str);

void	print_error(const char *message);
void	wait_msec(t_time time);
t_time	get_current_time(void);

int		init_table(t_table *table);
int		init_locks(t_table *table);
int		init_forks(t_table *table);
int		init_philos(t_table *table);
void	alloc_forks(t_table *table, const size_t index);

int		create_threads(t_table *table);
void	join_threads(t_table *table);
void	clear_forks(t_fork *forks, const size_t size);
void	clear_table(t_table *table);

void	*act(void *arg);
void	eat(t_philo *philo);
void	print_stat(t_philo *philo, const char *message);
int		is_over(t_philo *philo);
int		is_dead(t_philo *philo);

void	*check(void *arg);
int		check_all_threads(t_table *table);

#endif
