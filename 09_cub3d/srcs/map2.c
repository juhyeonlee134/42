/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:33:32 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/28 15:11:02 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_elements(t_map const *const map)
{
	size_t	h;
	size_t	w;
	int		is_player;

	h = 0;
	while (h < map->h)
	{
		w = 0;
		while (w < map->w)
		{
			is_player = check_player(map->map[h][w]);
			if (map->map[h][w] != '1' && map->map[h][w] != '0' && \
				map->map[h][w] != ' ' && map->map[h][w] != 'N' && \
				map->map[h][w] != 'E' && map->map[h][w] != 'S' && \
				map->map[h][w] != 'W')
				print_error(E_MAP_INVAL);
			w++;
		}
		h++;
	}
	if (is_player == 0)
		print_error(E_MAP_NOPLAYER);
}

int	check_player(char const el)
{
	static int	num_p;

	if (el == 'N' || el == 'E' || el == 'S' || el == 'W')
	{
		if (num_p != 0)
			print_error(E_MAP_2PLAYER);
		num_p = 1;
	}
	return (num_p);
}

void	check_surround(t_map const *const map)
{
	size_t	px;
	size_t	py;
	t_map	cmap;

	find_player(*map, &py, &px);
	copy_map(&cmap, *map);
	clear_map(cmap);
}

void	find_player(t_map const map, size_t *const y, size_t *const x)
{
	*y = 0;
	while (*y < map.h)
	{
		*x = 0;
		while (*x < map.w)
		{
			if (map.map[*y][*x] == 'N' || map.map[*y][*x] == 'E' || \
				map.map[*y][*x] == 'S' || map.map[*y][*x] == 'W')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	copy_map(t_map *const dst, t_map const org)
{
	size_t	index;

	dst->h = org.h;
	dst->w = org.w;
	dst->map = (char **)malloc(sizeof(char *) * org.h);
	if (!dst->map)
		print_error(E_ALLOC);
	index = 0;
	while (index < org.h)
	{
		dst->map[index] = ft_strdup(org.map[index]);
		if (!dst->map[index])
			print_error(E_ALLOC);
		index++;
	}
}
