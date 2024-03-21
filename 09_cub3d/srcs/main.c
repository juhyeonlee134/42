/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:13:16 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/21 23:09:00 by juhyelee         ###   ########.fr       */
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
	char		*textures[E_SZ];

	while (1)
	{
		ret = __get_string(fd);
		if (!ret)
			break ;
		if (__set_textures(textures, ret) == 0)
		{
			printf("error\n");
			free(ret);
			return (1);
		}
		free(ret);
	}
	for (size_t index = 0; index < E_SZ; index++)
	{
		printf("%s\n", textures[index]);
		free(textures[index]);
	}
	atexit(check);
	return (0);
}
