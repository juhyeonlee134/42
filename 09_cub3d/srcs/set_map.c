/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 01:58:16 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/25 18:44:29 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	__set_map(t_map *const map, char const *map_string)
{
	size_t	index;
	size_t	map_idx;
	size_t	line_len;

	map->map = (char **)malloc(sizeof(char *) * (map->map_h));
	if (!map->map)
		exit(EXIT_FAILURE);
	index = 0;
	map_idx = 0;
	while (index < map->map_h)
	{
		map->map[index] = (char *)malloc(sizeof(char) * (map->map_w + 1));
		if (!map->map_w)
			exit(EXIT_FAILURE);
		line_len = __get_line_len(map_string + map_idx);
		ft_strlcpy(map->map[index], map_string + map_idx, line_len + 1);
		__full_blank(map->map[index], map->map_w);
		map_idx += (line_len + 1);
		index++;
	}
}

void	__set_map_size(char const *map_string, size_t *h, size_t *w)
{
	size_t	index;
	size_t	len;

	*h = 0;
	index = 0;
	while (map_string[index])
	{
		if (map_string[index] == '\n')
			(*h)++;
		index++;
	}
	*w = 0;
	index = 0;
	while (map_string[index])
	{
		len = __get_line_len(map_string + index);
		if (*w < len)
			*w = len;
		index += (len + 1);
	}
}

size_t	__get_line_len(char const *string)
{
	size_t	line_len;

	line_len = 0;
	while (string[line_len] && string[line_len] != '\n')
		line_len++;
	return (line_len);
}

void	__full_blank(char *map, size_t const w)
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
