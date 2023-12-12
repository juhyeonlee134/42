/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:08:59 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/06 16:27:29 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	push(t_stack *from, t_stack *to)
{
	size_t	to_push;

	if (from->size == 0)
		return (0);
	to_push = from->lst->data;
	remove_front(from);
	insert_front(to, to_push);
	return (1);
}

int	swap(t_stack *stack)
{
	size_t	to_swap;

	if (stack->size <= 1)
		return (0);
	to_swap = stack->lst->data;
	stack->lst->data = stack->lst->next->data;
	stack->lst->next->data = to_swap;
	return (1);
}

void	rotate(t_stack *stack)
{
	stack->lst = stack->lst->next;
}

void	reverse(t_stack *stack)
{
	stack->lst = stack->lst->prev;
}
