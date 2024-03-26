/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:13:16 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/26 13:28:43 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	main(int argc, char *argv[])
{
	t_map	map;

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
	init_map(&map, argv[1]);
	printf("textures : %s | %s | %s | %s\n", \
		map.textures[0], map.textures[1], map.textures[2], map.textures[3]);
	printf("colros : %d,%d,%d | %d,%d,%d\n", \
		map.colors[0][0], map.colors[0][1], map.colors[0][2], \
		map.colors[1][0], map.colors[1][1], map.colors[1][2]);
	for (size_t h = 0; h < map.h; h++)
		printf("%s\n", map.map[h]);
	clear_map(&map);
	return (0);
}
