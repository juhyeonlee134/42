/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 06:23:45 by juhyelee          #+#    #+#             */
/*   Updated: 2023/09/08 20:06:29 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	found_player_pos(t_info *info)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{
			if (info->map[y][x] == 'P')
			{
				info->player.x = x;
				info->player.y = y;
			}
			x++;
		}
		y++;
	}
}

void	check_all_path(t_info *info, const int x, const int y)
{
	info->map[info->player.y][info->player.x] = '1';
	if (check_path(info, 0, 1))
		check_all_path(info, 0, 1);
	if (check_path(info, 1, 0))
		check_all_path(info, 1, 0);
	if (check_path(info, 0, -1))
		check_all_path(info, 0, -1);
	if (check_path(info, -1, 0))
		check_all_path(info, -1, 0);
	if (x == 1)
		info->player.x--;
	else if (x == -1)
		info->player.x++;
	else if (y == 1)
		info->player.y--;
	else
		info->player.y++;
}

int	check_path(t_info *info, const int x, const int y)
{
	int	to_x;
	int	to_y;

	to_x = info->player.x + x;
	to_y = info->player.y + y;
	if (to_x >= info->width || to_y >= info->height)
		return (0);
	else if (info->map[to_y][to_x] == '1' || info->map[to_y][to_x] == 'R')
		return (0);
	else if (info->map[to_y][to_x] == 'C')
		info->c_num++;
	else if (info->map[to_y][to_x] == 'E')
		info->e_num++;
	info->player.x = to_x;
	info->player.y = to_y;
	return (1);
}
