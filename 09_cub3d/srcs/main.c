/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:13:16 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/20 15:21:29 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	todo : __get_string에서 메모리 누수 찾기
*/
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
	//char		*textures[E_SZ];

	while (1)
	{
		ret = __get_string(fd);
		if (!ret)
			break ;
		//if (__set_textures(textures, ret) == 0)
		//{
		//	printf("error\n");
		//	free(ret);
		//	return (1);
		//}
		free(ret);
	}
	//printf("%s\n%s\n%s\n%s\n", textures[0], textures[1], textures[2], textures[3]);
	//free(textures[0]);
	//free(textures[1]);
	//free(textures[2]);
	//free(textures[3]);
	atexit(check);
	return (0);
}
