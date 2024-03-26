/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:26:58 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/26 20:00:28 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	__init_map(t_map *const map, int const fd)
{
	char	*in_str;
	char	*map_str;
	size_t	start_point;

	map_str = NULL;
	while (1)
	{
		in_str = get_next_line(fd);
		if (!in_str)
			break ;
		map_str = __merge(map_str, in_str);
		free(in_str);
	}
	start_point = 0;
	while (map_str[start_point] && map_str[start_point] == '\n')
		start_point++;
	map->h = __get_height(map_str + start_point);
	map->w = __get_width(map_str + start_point);
	__init_map_context(map, map_str + start_point);
	__check_map(*map);
	free(map_str);
}

size_t	__get_height(char const *str)
{
	size_t	height;

	height = 0;
	while (*str)
	{
		if (*str == '\n')
			height++;
		str++;
	}
	if (height < 3)
	{
		perror("invalid map: height must be at least 3");
		exit(EXIT_FAILURE);
	}
	return (height);
}

size_t	__get_width(char const *const str)
{
	size_t	width;
	size_t	index;
	size_t	line_len;

	width = 0;
	index = 0;
	while (str[index])
	{
		line_len = __get_line_len(str + index);
		if (width < line_len)
			width = line_len;
		index += (line_len + 1);
	}
	if (width < 3)
	{
		perror("invalid map: width must be at least 3");
		exit(EXIT_FAILURE);
	}
	return (width);
}

void	__init_map_context(t_map *const map, char const *str)
{
	size_t	h_idx;
	size_t	map_idx;
	size_t	line_len;

	map->map = (char **)malloc(sizeof(char *) * (map->h));
	if (!map->map)
		exit(EXIT_FAILURE);
	h_idx = 0;
	map_idx = 0;
	while (h_idx < map->h)
	{
		map->map[h_idx] = (char *)malloc(sizeof(char) * (map->w + 1));
		if (!map->w)
			exit(EXIT_FAILURE);
		line_len = __get_line_len(str + map_idx);
		ft_strlcpy(map->map[h_idx], str + map_idx, line_len + 1);
		__full_blank(map->map[h_idx], map->w);
		map_idx += (line_len + 1);
		h_idx++;
	}
}

void	__full_blank(char *const map, size_t const w)
{
	size_t	index;

	index = 0;
	while (map[index])
		index++;
	while (index < w)
	{
		map[index] = ' ';
		index++;
	}
	map[w] = '\0';
}
