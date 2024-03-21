/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:13:16 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/21 23:56:27 by juhyelee         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_sources	sources;

	if (argc < 2)
	{
		perror("Need more argument\n");
		return (1);
	}
	if (argc > 2)
	{
		perror("Too many arguments\n");
		return (1);
	}
	init_sources(&sources, argv[1]);
	printf("%s\n%s\n%s\n%s\n", sources.textures[0], sources.textures[1], sources.textures[2], sources.textures[3]);
	printf("%d, %d, %d\n", sources.colors[0][0], sources.colors[0][1], sources.colors[0][2]);
	printf("%d, %d, %d\n", sources.colors[1][0], sources.colors[1][1], sources.colors[1][2]);
	atexit(check);
	return (0);
}
