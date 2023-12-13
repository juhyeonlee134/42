/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:00:31 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/13 18:00:18 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse(const size_t argc, const char *argv[], t_data *data)
{
	if (argc < 5 || argc > 6)
		return (print_error("the number of argument must be 5~6"), 0);
	data->size = convert_to_num(argv[1]);
	data->dead = convert_to_num(argv[2]);
	data->eating = convert_to_num(argv[3]);
	data->sleeping = convert_to_num(argv[4]);
	data->cnt = NO_OPT;
	if (argc == 6)
		data->cnt = convert_to_num(argv[5]);
	return (is_invalid(*data));
}

int	is_invalid(const t_data data)
{
	if (data.size == (size_t)-1 || data.size == 0)
		return (print_error("invalid argument"), 0);
	if (data.dead == (size_t)-1 || data.dead == 0)
		return (print_error("invalid argument"), 0);
	if (data.eating == (size_t)-1 || data.eating == 0)
		return (print_error("invalid argument"), 0);
	if (data.sleeping == (size_t)-1 || data.sleeping == 0)
		return (print_error("invalid argument"), 0);
	if (data.cnt == -1 || data.cnt == 0)
		return (print_error("invalid argument"), 0);
	return (1);
}

void	print_error(const char *message)
{
	write(STDERR_FILENO, "Error: ", 7);
	while (*message)
	{
		write(STDERR_FILENO, message, 1);
		message++;
	}
	write(STDERR_FILENO, "\n", 1);
}

size_t	convert_to_num(const char *str)
{
	size_t	num;

	num = 0;
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

int	is_not_dead(t_thread *thread)
{
	pthread_mutex_lock(thread->to_check);
	if (thread->stat == e_dead)
		return (pthread_mutex_unlock(thread->to_check), 0);
	pthread_mutex_unlock(thread->to_check);
	return (1);
}
