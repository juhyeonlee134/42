/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cheap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:57:41 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/06 23:37:15 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	cheap_ins_to_b(t_stacks *stacks)
{
	size_t		index;
	t_node		*a_node;
	t_ins_cnt	ins;

	get_ins_to_b(*stacks, 0, stacks->a->lst->data, &(stacks->ins));
	index = 1;
	a_node = stacks->a->lst->next;
	while (index < stacks->a->size)
	{
		get_ins_to_b(*stacks, index, a_node->data, &ins);
		if (sum_of(stacks->ins) > sum_of(ins))
			stacks->ins = ins;
		index++;
		a_node = a_node->next;
	}
}

void	cheap_ins_to_a(t_stacks *stacks)
{
	size_t		index;
	t_node		*b_node;
	t_ins_cnt	ins;

	get_ins_to_a(*stacks, 0, stacks->b->lst->data, &(stacks->ins));
	index = 1;
	b_node = stacks->b->lst->next;
	while (index < stacks->b->size)
	{
		get_ins_to_a(*stacks, index, b_node->data, &ins);
		if (sum_of(stacks->ins) > sum_of(ins))
			stacks->ins = ins;
		index++;
		b_node = b_node->next;
	}
}

void	get_ins_to_b(const t_stacks stacks, const size_t index, \
const size_t data, t_ins_cnt *ins)
{
	size_t	to_insert;

	empty_ins_cnt(ins);
	if (index <= stacks.a->size / 2)
		ins->ra = index;
	else
		ins->rra = stacks.a->size - index;
	to_insert = find_to_insert_by_dec(*stacks.b, data);
	if (to_insert <= stacks.b->size / 2)
		ins->rb = to_insert;
	else
		ins->rrb = stacks.b->size - to_insert;
	ins->pb++;
	optimization_rotate(ins);
	optimization_reverse(ins);
}

void	get_ins_to_a(const t_stacks stacks, const size_t index, \
const size_t data, t_ins_cnt *ins)
{
	size_t	to_insert;

	empty_ins_cnt(ins);
	if (index <= stacks.b->size / 2)
		ins->rb = index;
	else
		ins->rrb = stacks.b->size - index;
	to_insert = find_to_insert_by_asc(*stacks.a, data);
	if (to_insert <= stacks.a->size / 2)
		ins->ra = to_insert;
	else
		ins->rra = stacks.a->size - to_insert;
	ins->pa++;
	optimization_rotate(ins);
	optimization_reverse(ins);
}

size_t	find_to_insert_by_dec(const t_stack stack, const size_t data)
{
	size_t	max;
	size_t	min;
	size_t	index;

	max = find_max(stack);
	min = find_min(stack);
	if (data > max)
		return (index_of(stack, max));
	else if (data < min)
		return (index_of(stack, min) + 1);
	else
		index = find_index_by_dec(stack, data);
	if (index == stack.size)
		return (0);
	return (index);
}
