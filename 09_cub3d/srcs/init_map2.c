/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:37:20 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/26 20:08:40 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

size_t	__get_line_len(char const *str)
{
	size_t	line_len;

	line_len = 0;
	while (str[line_len] && str[line_len] != '\n')
		line_len++;
	return (line_len);
}

void	__check_map(t_map const map)
{
	size_t	h;
	size_t	w;

	__check_element(map);
	__go_to_wall(map, &h, &w);
	__check_surround(map, h, w);
}

void	__check_element(t_map const map)
{
	size_t	h;

	h = 0;
	while (h < map.h)
	{
		__check_one_line(map.map[h]);
		h++;
	}
}

void	__check_one_line(char const *str)
{
	static int	flag;

	while (*str)
	{
		if (*str == 'N' || *str == 'E' || *str == 'S' || *str == 'W')
		{
			if (flag)
			{
				perror("invalid map: player must be one");
				exit(EXIT_FAILURE);
			}
			else
				flag = 1;
		}
		else if (*str != ' ' && *str != '1' && *str != '0')
		{
			perror("invalid map: invalid element");
			exit(EXIT_FAILURE);
		}
		str++;
	}
}

void	__go_to_wall(t_map const map, size_t *const h, size_t *const w)
{
	*h = 0;
	while (*h < map.h)
	{
		*w = 0;
		while (*w < map.w)
		{
			if (map.map[*h][*w] == '0')
				break ;
			if (map.map[*h][*w] == '1')
				return ;
			(*w)++;
		}
		(*h)++;
	}
	perror("invalid map: no wall");
	exit(EXIT_FAILURE);
}
