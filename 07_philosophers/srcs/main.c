/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:43:45 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/12 23:30:21 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "mutex.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_fork	*forks;
	t_mutex	*to_print;
	t_mutex	*to_eat;
	t_mutex	*to_check;
	t_data	data;

	if (!parse(argc, (const char **)argv, &data))
		return (1);
	forks = set_forks(data.size);
	if (!forks)
		return (1);
	to_print = set_mutex();
	if (!to_print)
		return (1);
	to_eat = set_mutex();
	if (!to_eat)
		return (1);
	to_check = set_mutex();
	if (!to_check)
		return (1);
	return (0);
}
