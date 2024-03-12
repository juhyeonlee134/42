/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 06:00:50 by juhyelee          #+#    #+#             */
/*   Updated: 2023/09/08 20:15:53 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_valid_root(const char **map)
{
	t_info	info;
	size_t	e_num;
	size_t	c_num;

	info.width = ft_strlen(map[0]);
	info.height = get_height_by_map(map);
	dup_map(&info, map);
	if (!info.map)
	{
		print_error(FAILED_MALLOC);
		return (0);
	}
	found_player_pos(&info);
	info.e_num = 0;
	info.c_num = 0;
	check_element(map, &e_num, &c_num);
	check_all_path(&info, 0, 0);
	clear_map(info.map, info.height);
	if (info.c_num != c_num || info.e_num != e_num)
		return (0);
	return (1);
}

void	dup_map(t_info *info, const char **map)
{
	size_t	index;

	info->map = (char **)malloc(sizeof(char *) * (info->height + 1));
	if (!info->map)
		return ;
	index = 0;
	while (index < (size_t)info->height)
	{
		info->map[index] = ft_strdup(map[index]);
		if (!info->map[index])
		{
			clear_map(info->map, index);
			return ;
		}
		index++;
	}
	info->map[index] = NULL;
}

void	check_element(const char **map, size_t *e_num, size_t *c_num)
{
	size_t	y;
	size_t	x;

	*e_num = 0;
	*c_num = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				(*c_num)++;
			else if (map[y][x] == 'E')
				(*e_num)++;
			x++;
		}
		y++;
	}
}

void	clear_map(char **map, const size_t index)
{
	size_t	idx;

	idx = 0;
	while (idx <= index)
	{
		free(map[idx]);
		idx++;
	}
	free(map);
}

size_t	get_height_by_map(const char **map)
{
	size_t	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}
