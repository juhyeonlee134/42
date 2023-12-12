/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:43:20 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/06 23:17:33 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort(t_stacks *stacks)
{
	if (stacks->a->size <= 1)
		return ;
	else if (stacks->a->size == 2)
		sa(stacks);
	else if (stacks->a->size == 3)
		sort_three(stacks);
	else
		sort_many(stacks);
}

void	sort_two(t_stacks *stacks)
{
	if (index_of(*stacks->a, find_max(*stacks->a)) != 1)
		sa(stacks);
}

void	sort_three(t_stacks *stacks)
{
	size_t	index_of_max;

	index_of_max = index_of(*stacks->a, find_max(*stacks->a));
	if (index_of_max == 0)
		ra(stacks);
	else if (index_of_max == 1)
		rra(stacks);
	if (index_of(*stacks->a, find_min(*stacks->a)) != 0)
		sa(stacks);
}

void	sort_many(t_stacks *stacks)
{
	pb(stacks);
	pb(stacks);
	while (stacks->a->size > 3)
	{
		empty_ins_cnt(&(stacks->ins));
		cheap_ins_to_b(stacks);
		execute_ins(stacks);
	}
	if (stacks->a->size == 2)
		sort_two(stacks);
	else if (stacks->a->size == 3)
		sort_three(stacks);
	empty_ins_cnt(&(stacks->ins));
	while (stacks->b->size != 0)
	{
		empty_ins_cnt(&(stacks->ins));
		cheap_ins_to_a(stacks);
		execute_ins(stacks);
	}
	finish_to_sort(stacks);
}
