/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_ins_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:12:01 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/06 16:30:41 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

void	ra(t_stacks *stacks)
{
	rotate(stacks->a);
	stacks->ins.ra--;
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	rb(t_stacks *stacks)
{
	rotate(stacks->b);
	stacks->ins.rb--;
	ft_putendl_fd("rb", STDOUT_FILENO);
}

void	rr(t_stacks *stacks)
{
	rotate(stacks->a);
	rotate(stacks->b);
	stacks->ins.rr--;
	ft_putendl_fd("rr", STDOUT_FILENO);
}

void	rra(t_stacks *stacks)
{
	reverse(stacks->a);
	stacks->ins.rra--;
	ft_putendl_fd("rra", STDOUT_FILENO);
}

void	rrb(t_stacks *stacks)
{
	reverse(stacks->b);
	stacks->ins.rrb--;
	ft_putendl_fd("rrb", STDOUT_FILENO);
}
