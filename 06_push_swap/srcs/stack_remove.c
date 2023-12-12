/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:37:53 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/06 23:36:49 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	clear_stack(t_stack *stack)
{
	while (stack->size)
	{
		remove_back(stack);
	}
	free(stack);
}

void	remove_one_node(t_stack *stack, t_node *del_node)
{
	del_node->prev->next = stack->lst;
	stack->lst->prev = del_node->prev;
	free(del_node);
}

void	remove_front(t_stack *stack)
{
	t_node	*del_node;

	del_node = stack->lst;
	stack->lst = stack->lst->next;
	remove_one_node(stack, del_node);
	stack->size--;
}

void	remove_back(t_stack *stack)
{
	t_node	*del_node;

	del_node = stack->lst->prev;
	remove_one_node(stack, del_node);
	stack->size--;
}
