/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:05:14 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/26 21:13:17 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	__check_surround(t_map map, size_t const h, size_t const w)
{
	size_t	h_idx;
	size_t	w_idx;

	h_idx = h;
	w_idx = w;
	__walk_down(&map, &h_idx, &w_idx);
	if (h_idx != h || w_idx != w)
	{
		perror("invalid map: not surround by wall");
		exit(EXIT_FAILURE);
	}
}

void	__walk_down(t_map *const map, size_t *const h, size_t *const w)
{
	map->map[*h][*w] = '0';
	if (*w > 0 && map->map[*h][*w - 1] == '1')
	{
		(*w)--;
		__walk_left(map, h, w);
	}
	if (*h  + 1 < map->h && map->map[*h + 1][*w] == '1')
	{
		(*h)++;
		__walk_down(map, h, w);
	}
	if (*w < map->w && map->map[*h][*w + 1] == '1')
	{
		(*w)++;
		__walk_right(map, h, w);
	}
	if (*h > 0 && map->map[*h - 1][*w] == '1')
	{
		(*h)--;
		__walk_up(map, h, w);
	}
}

void	__walk_left(t_map *const map, size_t *const h, size_t *const w)
{
	map->map[*h][*w] = '0';
	if (*h > 0 && map->map[*h - 1][*w] == '1')
	{
		(*h)--;
		__walk_up(map, h, w);
	}
	if (*w > 0 && map->map[*h][*w - 1] == '1')
	{
		(*w)--;
		__walk_left(map, h, w);
	}
	if (*h + 1 < map->h && map->map[*h + 1][*w] == '1')
	{
		(*h)++;
		__walk_down(map, h, w);
	}
	if (*w < map->w && map->map[*h][*w + 1] == '1')
	{
		(*w)++;
		__walk_right(map, h,w);
	}
}

void	__walk_right(t_map *const map, size_t *const h, size_t *const w)
{
	map->map[*h][*w] = '0';
	if (*h + 1 < map->h && map->map[*h + 1][*w] == '1')
	{
		(*h)++;
		__walk_down(map, h, w);
	}
	if (*w < map->w && map->map[*h][*w + 1] == '1')
	{
		(*w)++;
		__walk_right(map, h, w);
	}
	if (*h > 0 && map->map[*h - 1][*w] == '1')
	{
		(*h)--;
		__walk_up(map, h, w);
	}
	if (*w > 0 && map->map[*h][*w - 1] == '1')
	{
		(*w)--;
		__walk_left(map, h, w);
	}
}

void	__walk_up(t_map *const map, size_t *const h, size_t *const w)
{
	map->map[*h][*w] = '0';
	if (*w < map->w && map->map[*h][*w + 1] == '1')
	{
		(*w)++;
		__walk_right(map, h, w);
	}
	if (*h > 0 && map->map[*h - 1][*w] == '1')
	{
		(*h)--;
		__walk_up(map, h, w);
	}
	if (*w > 0 && map->map[*h][*w - 1] == '1')
	{
		(*w)--;
		__walk_left(map, h, w);
	}
	if (*h  + 1 < map->h && map->map[*h + 1][*w] == '1')
	{
		(*h)++;
		__walk_down(map, h, w);
	}
}
