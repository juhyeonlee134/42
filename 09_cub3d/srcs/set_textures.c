/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:29:51 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/21 23:13:36 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <fcntl.h>
#include <stdlib.h>

void	__set_textures(char *textures[], char const *const string)
{
	t_index const	index = __identify_type(string);

	if (index == E_ER)
	{
		/* print error message */
		exit(EXIT_FAILURE);
	}
	if (index == E_NO)
		textures[E_NO] = __get_source(string);
	else if (index == E_SO)
		textures[E_SO] = __get_source(string);
	else if (index == E_WE)
		textures[E_WE] = __get_source(string);
	else if (index == E_EA)
		textures[E_EA] = __get_source(string);
	else if (index == E_FL)
		textures[E_FL] = __get_source(string);
	else if (index == E_CE)
		textures[E_CE] = __get_source(string);
}

t_index	__identify_type(char const *string)
{
	t_index	ret;

	ret = E_ER;
	if (ft_strncmp(string, "NO", 2) == 0 && string[2] == ' ')
		ret = E_NO;
	else if (ft_strncmp(string, "SO", 2) == 0 && string[2] == ' ')
		ret = E_SO;
	else if (ft_strncmp(string, "WE", 2) == 0 && string[2] == ' ')
		ret = E_WE;
	else if (ft_strncmp(string, "EA", 2) == 0 && string[2] == ' ')
		ret = E_EA;
	else if (string[0] == 'F' && string[1] == ' ')
		ret = E_FL;
	else if (string[0] == 'C' && string[1] == ' ')
		ret = E_CE;
	else if (string[0] == '\n' && string[1] == '\0')
		ret = E_NL;
	return (ret);
}

char	*__get_source(char const *string)
{
	char	**strings;
	char	*source;
	size_t	index;

	strings = ft_split(string, ' ');
	if (!strings)
		exit(EXIT_FAILURE);
	source = ft_strdup(strings[1]);
	if (!source)
		exit(EXIT_FAILURE);
	index = 0;
	while (strings[index])
	{
		free(strings[index]);
		index++;
	}
	free(strings);
	return (source);
}
