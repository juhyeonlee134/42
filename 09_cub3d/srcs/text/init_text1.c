/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:03:12 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/25 21:12:37 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "text.h"
#include <stdio.h>

void	init_text(t_text *const text, int const fd)
{
	char	*str;
	int		is_full;

	is_full = 0;
	while (!is_full)
	{
		str = get_next_line(fd);
		if (!str)
		{
			perror("invalid file");
			exit(EXIT_FAILURE);
		}
		is_full = __init_textures(text, str);
		free(str);
	}
}

void	__set_color(t_color *color, char const *string)
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

char	*__set_texture(char const *string)
{
	char			*texture;
	size_t const	start_point = __check_string(string);

	texture = ft_strdup(string + start_point + 1);
	if (!texture)
		exit(EXIT_FAILURE);
	return (texture);
}

int	__init_textures(t_text *const text, char const *str)
{
	static size_t	cnt;
	t_id const		id = __get_id(str);

	if (id == E_ER)
	{
		perror("invalid file");
		exit(EXIT_FAILURE);
	}
	if (id > E_NL)
		cnt++;
	if (id >= E_NO && id <= E_EA)
		text->textures[id] = __set_texture(str);
	else if (id == E_FL || id == E_CE)
		__set_color(text->colors[id - 4], str);
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
