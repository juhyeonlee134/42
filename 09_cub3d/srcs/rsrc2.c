/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsrc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:09:20 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/28 13:08:19 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_color(t_color *const color, char const *str)
{
	size_t	index;

	while (*str && is_white(*str))
		str++;
	if (*str == '\0')
		print_error(E_NOCOL);
	index = 0;
	while (index < 3)
	{
		color[index] = convert_color(str);
		while (*str && ft_isdigit(*str))
			str++;
		str++;
		if (index != 2 && *str == '\0')
			print_error(E_LACKCOL);
		index++;
	}
	if (*str != '\0')
		print_error(E_MANYCOL);
}

t_color	convert_color(char const *str)
{
	t_color	color;
	char	*col_str;

	color = ft_atoi(str);
	col_str = ft_itoa(color);
	if (!col_str)
		print_error(E_ALLOC);
	if (ft_strncmp(str, col_str, ft_strlen(col_str)) != 0)
		print_error(E_INVCOL);
	free(col_str);
	return (color);
}
