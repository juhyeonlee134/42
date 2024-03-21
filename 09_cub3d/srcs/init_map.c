/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:43:18 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/22 03:50:02 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_map(t_map *const map, char const *const file_name)
{
	int const	fd = __open_file(file_name);

	if (fd < 0)
	{
		perror("not found file");
		exit(EXIT_FAILURE);
	}
	__init_sources(map, fd);
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

void	__init_sources(t_map *const map, int const fd)
{
	char	*string;
	int		is_full_sources;

	is_full_sources = 0;
	while (!is_full_sources)
	{
		string = __get_string(fd);
		if (!string)
		{
			perror("invalid file");
			exit(EXIT_FAILURE);
		}
		is_full_sources = __set_sources(map, string);
		free(string);
	}
}

void	__init_map(t_map *const map, int const fd)
{
	char	*string;
	char	*map_string;
	size_t	start_point;

	map_string = NULL;
	while (1)
	{
		string = __get_string(fd);
		if (!string)
			break ;
		map_string = __merge(map_string, string);
		free(string);
	}
	start_point = 0;
	while (map_string[start_point] && map_string[start_point] == '\n')
		start_point++;
	__set_map_size(map_string + start_point, &map->map_h, &map->map_w);
	__set_map(map, map_string + start_point);
	free(map_string);
}
