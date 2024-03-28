/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:26:00 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/28 16:07:15 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_around(t_map const map, size_t const y, size_t const x)
{
	map.map[y][x] = '1';
	if (check_up(map, y, x))
		check_around(map, y - 1, x);
	if (check_left(map, y, x))
		check_around(map, y, x - 1);
	if (check_down(map, y, x))
		check_around(map, y + 1, x);
	if (check_right(map, y, x))
		check_around(map, y, x + 1);
}

int	check_up(t_map const map, size_t const y, size_t const x)
{
	if (y == 0 || y + 1 == map.h)
		print_error(E_MAP_INVAL);
	else if (map.map[y - 1][x] == ' ')
		print_error(E_MAP_INVAL);
	return (map.map[y - 1][x] == '0');
}

int	check_left(t_map const map, size_t const y, size_t const x)
{
	if (x == 0 || map.map[y][x] == '\0')
		print_error(E_MAP_INVAL);
	else if (map.map[y][x - 1] == ' ')
		print_error(E_MAP_INVAL);
	return (map.map[y][x - 1] == '0');
}

int	check_down(t_map const map, size_t const y, size_t const x)
{
	if (y == 0 || y + 1 == map.h)
		print_error(E_MAP_INVAL);
	else if (map.map[y + 1][x] == ' ')
		print_error(E_MAP_INVAL);
	return (map.map[y + 1][x] == '0');
}

int	check_right(t_map const map, size_t const y, size_t const x)
{
	if (x == 0 || map.map[y][x] == '\0')
		print_error(E_MAP_INVAL);
	else if (map.map[y][x + 1] == ' ')
		print_error(E_MAP_INVAL);
	return (map.map[y][x + 1] == '0');
}
