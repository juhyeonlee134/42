/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:05:14 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/26 21:32:13 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	__check_surround(t_map map, size_t const h, size_t const w)
{
	__walk_down(&map, h, w, '1');
	if (map.map[h][w] != '+')
	{
		perror("invalid map: not surround by wall");
		exit(EXIT_FAILURE);
	}
}

void	__walk_down(t_map *const map, size_t const h, size_t const w, \
		char const del)
{
	map->map[h][w] = '0';
	if (w > 0 && map->map[h][w - 1] == del)
		__walk_left(map, h, w - 1, del);
	if (h  + 1 < map->h && map->map[h + 1][w] == del)
		__walk_down(map, h + 1, w, del);
	if (w < map->w && map->map[h][w + 1] == del)
		__walk_right(map, h, w + 1, del);
	if (h > 0 && map->map[h - 1][w] == del)
		__walk_up(map, h - 1, w, del);
	map->map[h][w] = '+';
}

void	__walk_left(t_map *const map, size_t const h, size_t const w, \
		char const del)
{
	map->map[h][w] = '0';
	if (h > 0 && map->map[h - 1][w] == del)
		__walk_up(map, h - 1, w, del);
	if (w > 0 && map->map[h][w - 1] == del)
		__walk_left(map, h, w - 1, del);
	if (h + 1 < map->h && map->map[h + 1][w] == del)
		__walk_down(map, h + 1, w, del);
	if (w < map->w && map->map[h][w + 1] == del)
		__walk_right(map, h, w + 1, del);
	map->map[h][w] = '+';
}

void	__walk_right(t_map *const map, size_t const h, size_t const w, \
		char const del)
{
	map->map[h][w] = '0';
	if (h + 1 < map->h && map->map[h + 1][w] == del)
		__walk_down(map, h + 1, w, del);
	if (w < map->w && map->map[h][w + 1] == del)
		__walk_right(map, h, w + 1, del);
	if (h > 0 && map->map[h - 1][w] == del)
		__walk_up(map, h - 1, w, del);
	if (w > 0 && map->map[h][w - 1] == del)
		__walk_left(map, h, w - 1, del);
	map->map[h][w] = '+';
}

void	__walk_up(t_map *const map, size_t const h, size_t const w, \
		char const del)
{
	map->map[h][w] = '0';
	if (w < map->w && map->map[h][w + 1] == del)
		__walk_right(map, h, w + 1, del);
	if (h > 0 && map->map[h - 1][w] == del)
		__walk_up(map, h - 1, w, del);
	if (w > 0 && map->map[h][w - 1] == del)
		__walk_left(map, h, w - 1, del);
	if (h  + 1 < map->h && map->map[h + 1][w] == del)
		__walk_down(map, h + 1, w, del);
	map->map[h][w] = '+';
}
