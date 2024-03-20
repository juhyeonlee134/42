/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:13:16 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/20 14:22:39 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void	check(void)
{
	system("leaks cub3d");
}

int	main(void)
{
	int const	fd = open("test", O_RDONLY);
	char		*ret;

	while (1)
	{
		ret = __get_string(fd);
		if (!ret)
			break ;
		printf("%s", ret);
		free(ret);
	}
	return (0);
}
