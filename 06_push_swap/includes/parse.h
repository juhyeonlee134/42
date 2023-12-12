/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:09:13 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/07 16:21:10 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "stack.h"

int		*check_is_num(char *str);
int		is_sign(char *str);
void	print_error(void);
void	split_args(t_list **list, char *arg);
void	check_is_black(char *str);
void	check_duplicate(t_list *list);
void	check_sorting(t_stack *stack);
void	clear_str_arr(char **str_arr);
size_t	how_many_min(int data, t_list *list);
t_list	*parse(int argc, char *argv[]);
t_stack	*indexing(t_list **list);

#endif
