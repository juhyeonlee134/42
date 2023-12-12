/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:26:35 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/07 11:54:17 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		exit(0);
	stack->lst = NULL;
	stack->size = 0;
	return (stack);
}

void	insert_new_node(t_stack *stack, t_node *new_node)
{
	new_node->prev = stack->lst->prev;
	new_node->next = stack->lst;
	stack->lst->prev->next = new_node;
	stack->lst->prev = new_node;
}

void	insert_front(t_stack *stack, const size_t data)
{
	t_node	*new_node;

	new_node = create_new_node(data);
	if (stack->lst)
		insert_new_node(stack, new_node);
	stack->lst = new_node;
	stack->size++;
}

void	insert_back(t_stack *stack, const size_t data)
{
	t_node	*new_node;

	new_node = create_new_node(data);
	if (stack->lst)
		insert_new_node(stack, new_node);
	else
		stack->lst = new_node;
	stack->size++;
}

t_node	*create_new_node(const size_t data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node)
	{
		new_node->data = data;
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	return (new_node);
}
