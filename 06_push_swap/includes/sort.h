/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:39:39 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/06 23:36:13 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "instruction.h"

typedef size_t(*t_index_of)(const t_stack, const size_t);

void	sort(t_stacks *stacks);
void	sort_two(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_many(t_stacks *stacks);
void	cheap_ins_to_b(t_stacks *stacks);
void	cheap_ins_to_a(t_stacks *stacks);
void	get_ins_to_a(const t_stacks stacks, const size_t index, \
const size_t data, t_ins_cnt *ins);
void	get_ins_to_b(const t_stacks stacks, const size_t index, \
const size_t data, t_ins_cnt *ins);
void	finish_to_sort(t_stacks *stacks);
void	optimization_rotate(t_ins_cnt *ins);
void	optimization_reverse(t_ins_cnt *ins);
size_t	find_to_insert_by_dec(const t_stack stack, const size_t data);
size_t	find_to_insert_by_asc(const t_stack stack, const size_t data);
size_t	find_index_by_asc(const t_stack stack, const size_t data);
size_t	find_index_by_dec(const t_stack stack, const size_t data);

#endif
