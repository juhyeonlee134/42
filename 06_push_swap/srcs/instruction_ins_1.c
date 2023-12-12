/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_ins_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:02:22 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/06 16:26:48 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

void	pa(t_stacks *stacks)
{
	if (push(stacks->b, stacks->a) == 0)
		return ;
	stacks->ins.pa--;
	ft_putendl_fd("pa", STDOUT_FILENO);
}

void	pb(t_stacks *stacks)
{
	if (push(stacks->a, stacks->b) == 0)
		return ;
	stacks->ins.pb--;
	ft_putendl_fd("pb", STDOUT_FILENO);
}

void	sa(t_stacks *stacks)
{
	if (swap(stacks->a) == 0)
		return ;
	stacks->ins.sa--;
	ft_putendl_fd("sa", STDOUT_FILENO);
}

void	sb(t_stacks *stacks)
{
	if (swap(stacks->b) == 0)
		return ;
	stacks->ins.sb--;
	ft_putendl_fd("sb", STDOUT_FILENO);
}

void	ss(t_stacks *stacks)
{
	swap(stacks->a);
	swap(stacks->b);
	stacks->ins.ss--;
	ft_putendl_fd("ss", STDOUT_FILENO);
}
