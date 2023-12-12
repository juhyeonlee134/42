/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 00:06:36 by juhyelee          #+#    #+#             */
/*   Updated: 2023/09/08 20:58:41 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_error(enum e_errnum errnum)
{
	ft_printf("ERROR : %s\n", strerror(errnum));
}

t_pos	*make_pos(void)
{
	return ((t_pos *)malloc(sizeof(t_pos)));
}

void	set_pos(t_pos *pos, const int x, const int y)
{
	pos->x = x;
	pos->y = y;
}

int	is_same_pos(t_pos *p1, t_pos *p2)
{
	if (p1->x == p2->x && p1->y == p2->y)
		return (1);
	return (0);
}
