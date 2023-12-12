/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:15:39 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/06 16:38:48 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

void	empty_ins_cnt(t_ins_cnt *ins)
{
	ft_memset(ins, 0, sizeof(t_ins_cnt));
}

void	rrr(t_stacks *stacks)
{
	reverse(stacks->a);
	reverse(stacks->b);
	stacks->ins.rrr--;
	ft_putendl_fd("rrr", STDOUT_FILENO);
}

void	execute_ins(t_stacks *stacks)
{
	while (stacks->ins.sa)
		sa(stacks);
	while (stacks->ins.sb)
		sb(stacks);
	while (stacks->ins.ss)
		ss(stacks);
	while (stacks->ins.ra)
		ra(stacks);
	while (stacks->ins.rb)
		rb(stacks);
	while (stacks->ins.rr)
		rr(stacks);
	while (stacks->ins.rra)
		rra(stacks);
	while (stacks->ins.rrb)
		rrb(stacks);
	while (stacks->ins.rrr)
		rrr(stacks);
	while (stacks->ins.pa)
		pa(stacks);
	while (stacks->ins.pb)
		pb(stacks);
}

size_t	sum_of(const t_ins_cnt ins)
{
	return (ins.pa + ins.pb + ins.sa + ins.sb + ins.ss + ins.ra + ins.rb + \
	ins.rr + ins.rra + ins.rrb + ins.rrr);
}
