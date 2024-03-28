/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsrc1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:59:12 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/28 13:03:05 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_file(char const *const file_name)
{
	size_t const	len = ft_strlen(file_name);
	int				fd;

	if (len < 4)
		print_error(E_INVFILE);
	if (ft_strncmp(file_name + (len - 4), ".cub", 4) != 0)
		print_error(E_INVFILE);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_error(E_FDERR);
	return (fd);
}

void	init_resource(t_rsrc *const rsrc, int const fd)
{
	char	*line;
	int		finished;
	t_type	type;

	finished = 0;
	while (finished < 6)
	{
		line = get_line(fd);
		if (!line)
			print_error(E_LACKINFO);
		line[ft_strlen(line) - 1] = '\0';
		type = get_type(line);
		if (type > T_NL)
			finished++;
		if (type >= T_NO && type <= T_EA)
			rsrc->textures[type] = set_texture(line + 2);
		else if (type == T_FL || type == T_CL)
			set_color(rsrc->colors[type - 4], line + 1);
		free(line);
	}
}

t_type	get_type(char const *str)
{
	if (*str == '\0')
		return (T_NL);
	while (*str && !is_white(*str))
		str++;
	if (str[-1] == 'F')
		return (T_FL);
	else if (str[-1] == 'C')
		return (T_CL);
	else if (str[-1] == 'O' && str[-2] == 'N')
		return (T_NO);
	else if (str[-1] == 'O' && str[-2] == 'S')
		return (T_SO);
	else if (str[-1] == 'E' && str[-2] == 'W')
		return (T_WE);
	else if (str[-1] == 'A' && str[-2] == 'E')
		return (T_EA);
	print_error(E_INVTYPE);
	return (-2);
}

int	is_white(char const ch)
{
	return (ch == ' ' || (ch >= 9 && ch <= 13));
}

char	*set_texture(char const *str)
{
	char	*texture;
	size_t	index;

	while (*str && is_white(*str))
		str++;
	if (*str == '\0')
		print_error(E_NOTXT);
	index = 0;
	while (str[index])
	{
		if (is_white(str[index]))
			print_error(E_MANYTXT);
		index++;
	}
	texture = ft_strdup(str);
	if (!texture)
		print_error(E_ALLOC);
	return (texture);
}
