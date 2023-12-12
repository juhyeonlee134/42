/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:42:25 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/06 15:49:17 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

size_t	find_min(const t_stack stack)
{
	size_t	min;
	size_t	index;
	t_node	*p;

	min = UINT_MAX;
	index = 0;
	p = stack.lst;
	while (index < stack.size)
	{
		if (min > p->data)
			min = p->data;
		index++;
		p = p->next;
	}
	return (min);
}

size_t	find_max(const t_stack stack)
{
	size_t	max;
	size_t	index;
	t_node	*p;

	max = 0;
	index = 0;
	p = stack.lst;
	while (index < stack.size)
	{
		if (max < p->data)
			max = p->data;
		index++;
		p = p->next;
	}
	return (max);
}

size_t	index_of(const t_stack stack, const size_t data)
{
	size_t	index;
	t_node	*p;

	index = 0;
	p = stack.lst;
	while (index < stack.size)
	{
		if (p->data == data)
			return (index);
		index++;
		p = p->next;
	}
	return (-1);
}
