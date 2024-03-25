/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:13:16 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/25 22:02:57 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_srcs	srcs;

	if (argc < 2)
	{
		perror("Need more argument");
		return (1);
	}
	if (argc > 2)
	{
		perror("Too many arguments");
		return (1);
	}
	init_sources(&srcs, argv[1]);
	printf("textures : %s | %s | %s | %s\n", \
		srcs.text.textures[0], srcs.text.textures[1], srcs.text.textures[2], srcs.text.textures[3]);
	printf("colros : %d,%d,%d | %d,%d,%d\n", \
		srcs.text.colors[0][0], srcs.text.colors[0][1], srcs.text.colors[0][2], \
		srcs.text.colors[1][0], srcs.text.colors[1][1], srcs.text.colors[1][2]);
	for (size_t h = 0; h < srcs.map.h; h++)
		printf("%s\n", srcs.map.map[h]);
	clear_textures(&srcs.text);
	clear_map(&srcs.map);
	return (0);
}
