/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 22:31:44 by juhyelee          #+#    #+#             */
/*   Updated: 2023/09/08 20:38:48 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_valid_map(const char **map)
{
	if (!is_rectangle(map))
		return (0);
	if (!is_wall_arround(map))
		return (0);
	if (!is_contain(map))
		return (0);
	return (1);
}

int	is_rectangle(const char **map)
{
	const size_t	len = ft_strlen(map[0]);
	size_t			index;

	index = 1;
	while (map[index])
	{
		if (len != ft_strlen(map[index]))
			return (0);
		index++;
	}
	return (1);
}

int	is_wall_arround(const char **map)
{
	size_t	index;
	size_t	len;

	if (!is_all_one(map[0]))
		return (0);
	index = 1;
	while (map[index + 1])
	{
		len = ft_strlen(map[index]);
		if (map[index][0] != '1' || map[index][len - 1] != '1')
			return (0);
		index++;
	}
	if (!is_all_one(map[index]))
		return (0);
	return (1);
}

int	is_all_one(const char *line)
{
	while (*line)
	{
		if (*line != '1')
			return (0);
		line++;
	}
	return (1);
}

int	is_contain(const char **map)
{
	t_num	num;
	size_t	index;

	num.player = 0;
	num.exit = 0;
	num.coin = 0;
	while (*map)
	{
		index = 0;
		while ((*map)[index])
		{
			if ((*map)[index] == 'P')
				num.player++;
			else if ((*map)[index] == 'E')
				num.exit++;
			else if ((*map)[index] == 'C')
				num.coin++;
			else if ((*map)[index] != '1' && (*map)[index] != '0')
				return (0);
			index++;
		}
		map++;
	}
	return (num.player == 1 && num.exit == 1 && num.coin >= 1);
}
