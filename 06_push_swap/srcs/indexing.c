/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:24:11 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/09 14:25:18 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_sign(char *str)
{
	if (ft_strlen(str) > 1)
	{
		if (str[0] == '+' && ft_isdigit(str[1]))
			return (1);
		else if (str[0] == '-' && str[1] == '0')
			return (1);
	}
	return (0);
}

void	check_is_black(char *str)
{
	size_t	black_num;
	size_t	index;

	black_num = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == ' ')
			black_num++;
		index++;
	}
	if (ft_strlen(str) == black_num)
		print_error();
}

void	check_sorting(t_stack *stack)
{
	size_t	index;
	t_node	*p;

	index = 0;
	p = stack->lst;
	while (index < stack->size)
	{
		if (index != p->data)
			return ;
		index++;
		p = p->next;
	}
	clear_stack(stack);
	exit(0);
}

size_t	how_many_min(int data, t_list *list)
{
	int	min_num;

	min_num = 0;
	while (list)
	{
		if (*(int *)(list->content) < data)
			min_num++;
		list = list->next;
	}
	return (min_num);
}

t_stack	*indexing(t_list **list)
{
	size_t	data;
	t_list	*node;
	t_stack	*stack;

	node = *list;
	stack = init_stack();
	while (node)
	{
		data = how_many_min(*(int *)(node->content), *list);
		insert_back(stack, data);
		node = node->next;
	}
	ft_lstclear(list, free);
	return (stack);
}
