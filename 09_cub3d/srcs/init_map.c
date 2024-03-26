/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:26:58 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/26 13:21:44 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	__init_map(t_map *const map, int const fd)
{
	char	*in_str;
	char	*map_str;
	size_t	spnt;

	map_str = NULL;
	while (1)
	{
		in_str = get_next_line(fd);
		if (!in_str)
			break ;
		map_str = __merge(map_str, in_str);
		free(in_str);
	}
	spnt = 0;
	while (map_str[spnt] && map_str[spnt] == '\n')
		spnt++;
	__init_map_size(map_str + spnt, &(map->h), &(map->w));
	__init_map_context(map, map_str + spnt);
	//__check_map(*map);
	free(map_str);
}

void	__init_map_size(char const *map_str, size_t *h, size_t *w)
{
	size_t	idx;
	size_t	len;

	*h = 0;
	idx = 0;
	while (map_str[idx])
	{
		if (map_str[idx] == '\n')
			(*h)++;
		idx++;
	}
	*w = 0;
	idx = 0;
	while (map_str[idx])
	{
		len = __get_line_len(map_str + idx);
		if (*w < len)
			*w = len;
		idx += (len + 1);
	}
}

void	__init_map_context(t_map *const map, char const *map_str)
{
	size_t	idx;
	size_t	map_idx;
	size_t	line_len;

	map->map = (char **)malloc(sizeof(char *) * (map->h));
	if (!map->map)
		exit(EXIT_FAILURE);
	idx = 0;
	map_idx = 0;
	while (idx < map->h)
	{
		map->map[idx] = (char *)malloc(sizeof(char) * (map->w + 1));
		if (!map->w)
			exit(EXIT_FAILURE);
		line_len = __get_line_len(map_str + map_idx);
		ft_strlcpy(map->map[idx], map_str + map_idx, line_len + 1);
		__full_blank(map->map[idx], map->w);
		map_idx += (line_len + 1);
		idx++;
	}
}

void	__full_blank(char *const map, size_t const w)
{
	size_t	idx;

	idx = 0;
	while (map[idx])
		idx++;
	while (idx < w)
	{
		map[idx] = ' ';
		idx++;
	}
	map[w] = '\0';
}

size_t	__get_line_len(char const *str)
{
	size_t	line_len;

	line_len = 0;
	while (str[line_len] && str[line_len] != '\n')
		line_len++;
	return (line_len);
}
