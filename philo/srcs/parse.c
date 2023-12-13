/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:30:31 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/13 21:58:03 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	parse(const size_t argc, const char *argv[], t_arguments *args)
{
	if (argc < 5 || argc > 6)
		return (print_error("The number of arguments must be 5~6"), 0);
	args->num_of_philos = convert_to_number(argv[1]);
	args->time_to_die = convert_to_number(argv[2]);
	args->time_to_eat = convert_to_number(argv[3]);
	args->time_to_sleep = convert_to_number(argv[4]);
	args->num_of_eating = NO_OPTION;
	if (argc == 6)
		args->num_of_eating = convert_to_number(argv[5]);
	if (args->num_of_philos == INCORRECT || args->num_of_philos == 0)
		return (print_error("1st argument is incorrect"), 0);
	if (args->time_to_die == INCORRECT || args->time_to_die == 0)
		return (print_error("2nd argument is incorrect"), 0);
	if (args->time_to_eat == INCORRECT || args->time_to_eat == 0)
		return (print_error("3rd argument is incorrect"), 0);
	if (args->time_to_sleep == INCORRECT || args->time_to_sleep == 0)
		return (print_error("4th argument is incorrect"), 0);
	if (args->num_of_eating == -1 || args->num_of_eating == 0)
		return (print_error("5th argument is incorrect"), 0);
	return (1);
}

t_long	convert_to_number(const char *str)
{
	t_long	number;

	number = 0;
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number);
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

void	wait_msec(t_time time)
{
	const t_time	start_time = get_current_time();

	while (get_current_time() - start_time < time)
		usleep(200);
}

t_time	get_current_time(void)
{
	struct timeval	current_time;
	t_time			result;

	gettimeofday(&current_time, NULL);
	result = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (result);
}
