/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:28:24 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/12 22:57:13 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef __uint128_t		t_time;
typedef pthread_t		t_thread;
typedef pthread_mutex_t	t_mutex;
typedef t_mutex			t_fork;

typedef enum e_stat
{
	e_ready,
	e_eat,
	e_dead
}t_stat;
typedef struct s_data
{
	size_t	size;
	size_t	cnt_eat;
	size_t	d_time;
	size_t	e_time;
	size_t	s_time;
}t_data;
typedef struct s_philo
{
	t_thread	*th;
	t_fork		*r;
	t_fork		*l;
	t_mutex		*to_print;
	t_mutex		*to_eat;
	t_mutex		*to_check;
	t_stat		*stat;
	t_data		data;
	t_time		start;
	t_time		last;
}t_philo;
typedef struct s_table
{
	t_philo	*philos;
	t_fork	*forks;
	t_mutex	*to_print;
	t_mutex	*to_eat;
	t_mutex	*to_check;
	t_data	data;
}t_table;

#endif
