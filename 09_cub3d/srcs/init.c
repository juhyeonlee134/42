/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:43:18 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/26 13:28:52 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <fcntl.h>

void	init_map(t_map *const map, char const *const file_name)
{
	int const	fd = __open_file(file_name);

	if (fd < 0)
	{
		perror("not found file");
		exit(EXIT_FAILURE);
	}
	__init_map_info(map, fd);
	__init_map(map, fd);
}

int	__open_file(char const *file_name)
{
	size_t const	len = ft_strlen(file_name);

	if (ft_strncmp(file_name + (len - 4), ".cub", 4) != 0)
	{
		perror("incorrect file");
		exit(EXIT_FAILURE);
	}
	return (open(file_name, O_RDONLY));
}

void	clear_map(t_map *const map)
{
	size_t	index;

	free(map->textures[0]);
	free(map->textures[1]);
	free(map->textures[2]);
	free(map->textures[3]);
	index = 0;
	while (index < map->h)
	{
		free(map->map[index]);
		index++;
	}
	free(map->map);
}
