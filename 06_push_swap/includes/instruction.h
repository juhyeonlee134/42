/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:50:21 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/06 16:35:45 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include "libft.h"
# include "stack.h"

typedef struct s_ins_cnt
{
	size_t	pa;
	size_t	pb;
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
}t_ins_cnt;

typedef struct s_stacks
{
	t_stack		*a;
	t_stack		*b;
	t_ins_cnt	ins;
}t_stacks;

void		empty_ins_cnt(t_ins_cnt *ins);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);
void		execute_ins(t_stacks *stacks);
size_t		sum_of(const t_ins_cnt ins);

#endif
