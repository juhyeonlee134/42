/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_optimization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:54:49 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/06 21:01:26 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

void	optimization_rotate(t_ins_cnt *ins)
{
	if (ins->ra >= ins->rb)
	{
		ins->ra -= ins->rb;
		ins->rr = ins->rb;
		ins->rb = 0;
	}
	else
	{
		ins->rb -= ins->ra;
		ins->rr = ins->ra;
		ins->ra = 0;
	}
}

void	optimization_reverse(t_ins_cnt *ins)
{
	if (ins->rra >= ins->rrb)
	{
		ins->rra -= ins->rrb;
		ins->rrr = ins->rrb;
		ins->rrb = 0;
	}
	else
	{
		ins->rrb -= ins->rra;
		ins->rrr = ins->rra;
		ins->rra = 0;
	}
}
