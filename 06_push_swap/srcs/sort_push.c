/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:08:56 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/07 11:51:45 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

size_t	find_to_insert_by_asc(const t_stack stack, const size_t data)
{
	size_t	max;
	size_t	min;
	size_t	index;

	max = find_max(stack);
	min = find_min(stack);
	if (data > max)
		index = index_of(stack, max) + 1;
	else if (data < min)
		index = index_of(stack, min);
	else
		index = find_index_by_asc(stack, data);
	if (index == stack.size)
		return (0);
	return (index);
}

size_t	find_index_by_asc(const t_stack stack, const size_t data)
{
	size_t	index;
	t_node	*p;

	index = 0;
	p = stack.lst;
	while (index + 1 < stack.size)
	{
		if (p->data < data && p->next->data > data)
			break ;
		index++;
		p = p->next;
	}
	return (index + 1);
}

size_t	find_index_by_dec(const t_stack stack, const size_t data)
{
	size_t	index;
	t_node	*p;

	index = 0;
	p = stack.lst;
	while (index + 1 < stack.size)
	{
		if (p->data > data && p->next->data < data)
			break ;
		index++;
		p = p->next;
	}
	return (index + 1);
}

void	finish_to_sort(t_stacks *stacks)
{
	size_t	min;
	size_t	index;

	empty_ins_cnt(&(stacks->ins));
	min = find_min(*stacks->a);
	index = index_of(*stacks->a, min);
	if (index <= stacks->a->size / 2)
		stacks->ins.ra = index;
	else
		stacks->ins.rra = stacks->a->size - index;
	execute_ins(stacks);
}
