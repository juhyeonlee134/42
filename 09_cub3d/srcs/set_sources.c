/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sources.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 01:13:53 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/25 18:26:12 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	__set_sources(t_map *const map, char const *string)
{
	static size_t	cnt;
	t_id const		id = __get_id(string);

	if (id == E_ER)
	{
		perror("invalid file");
		exit(EXIT_FAILURE);
	}
	if (id > E_NL)
		cnt++;
	if (id >= E_NO && id <= E_EA)
		map->textures[id] = __set_texture(string);
	else if (id == E_FL || id == E_CE)
		__set_color(map->colors[id - 4], string);
	if (cnt == 6)
		return (1);
	return (0);
}

t_id	__get_id(char const *string)
{
	if (ft_strncmp(string, "NO ", 3) == 0)
		return (E_NO);
	if (ft_strncmp(string, "SO ", 3) == 0)
		return (E_SO);
	if (ft_strncmp(string, "WE ", 3) == 0)
		return (E_WE);
	if (ft_strncmp(string, "EA ", 3) == 0)
		return (E_EA);
	if (ft_strncmp(string, "F ", 2) == 0)
		return (E_FL);
	if (ft_strncmp(string, "C ", 2) == 0)
		return (E_CE);
	if (string[0] == '\n' && string[1] == '\0')
		return (E_NL);
	return (E_ER);
}

char	*__set_texture(char const *string)
{
	char			*texture;
	size_t const	start_point = __check_string(string);

	texture = ft_strdup(string + start_point + 1);
	if (!texture)
		exit(EXIT_FAILURE);
	return (texture);
}

void	__set_color(unsigned char *color, char const *string)
{
	size_t const	start_point = __check_string(string);

	string += start_point;
	color[0] = __convert_to_num(string);
	if (*string == '-' || *string == '+')
		string++;
	while (ft_isdigit(*string))
		string++;
	string++;
	color[1] = __convert_to_num(string);
	if (*string == '-' || *string == '+')
		string++;
	while (ft_isdigit(*string))
		string++;
	string++;
	color[2] = __convert_to_num(string);
}

size_t	__check_string(char const *string)
{
	size_t	cnt;
	size_t	check;

	cnt = 0;
	while (string[cnt] && string[cnt] != ' ')
		cnt++;
	if (string[cnt] == '\0')
	{
		perror("invalid file");
		exit(EXIT_FAILURE);
	}
	cnt++;
	check = cnt;
	while (string[check])
	{
		if (string[check] == ' ')
		{
			perror("invalid file");
			exit(EXIT_FAILURE);
		}
		check++;
	}
	return (cnt);
}
