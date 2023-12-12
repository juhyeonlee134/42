/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:23:09 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/06 23:36:58 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# define UINT_MAX 4294967295

typedef struct s_node
{
	size_t			data;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

typedef struct s_stack
{
	t_node	*lst;
	size_t	size;
}t_stack;

int		push(t_stack *from, t_stack *to);
int		swap(t_stack *stack);
void	clear_stack(t_stack *stack);
void	insert_new_node(t_stack *stack, t_node *new_node);
void	insert_front(t_stack *stack, const size_t data);
void	insert_back(t_stack *stack, const size_t data);
void	remove_one_node(t_stack *stack, t_node *del_node);
void	remove_front(t_stack *stack);
void	remove_back(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse(t_stack *stack);
size_t	find_min(const t_stack stack);
size_t	find_max(const t_stack stack);
size_t	index_of(const t_stack stack, const size_t data);
t_node	*create_new_node(const size_t data);
t_stack	*init_stack(void);

#endif
