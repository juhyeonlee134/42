/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:17:13 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/28 13:20:24 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(enum e_error num)
{
	if (num == E_ALLOC)
		ft_putendl_fd(strerror(ENOMEM), 2);
	else if (num == E_NOFILE)
		ft_putendl_fd(strerror(ENOENT), 2);
	else if (num == E_ARGNUM)
		ft_putendl_fd(strerror(E2BIG), 2);
	else if (num == E_INVFILE)
		ft_putendl_fd("Is not .cub file", 2);
	else if (num == E_FDERR)
		ft_putendl_fd("File descriptor is negative", 2);
	resrouce_error(num);
	exit(EXIT_FAILURE);
}

void	resrouce_error(enum e_error num)
{
	if (num == E_LACKINFO)
		ft_putendl_fd("Need more map information", 2);
	else if (num == E_INVTYPE)
		ft_putendl_fd("Invalid type", 2);
	else if (num == E_NOTXT)
		ft_putendl_fd("Not found texture file", 2);
	else if (num == E_MANYTXT)
		ft_putendl_fd("Too many texture", 2);
	else if (num == E_NOCOL)
		ft_putendl_fd("Not found color", 2);
	else if (num == E_LACKCOL)
		ft_putendl_fd("Need more color", 2);
	else if (num == E_MANYCOL)
		ft_putendl_fd("Too many color", 2);
	else if (num == E_INVCOL)
		ft_putendl_fd("Invalid color", 2);
}
