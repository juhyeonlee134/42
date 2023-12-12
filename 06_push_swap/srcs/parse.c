/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:59:52 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/09 15:18:54 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	*check_is_num(char *str)
{
	int		num;
	int		*ret;
	char	*check_str;

	num = ft_atoi(str);
	check_str = ft_itoa(num);
	if (is_sign(str))
		str++;
	if (ft_strncmp(str, check_str, ft_strlen(str)) != 0)
		print_error();
	ret = (int *)malloc(sizeof(int));
	if (ret == NULL)
		print_error();
	*ret = num;
	free(check_str);
	return (ret);
}

void	split_args(t_list **list, char *arg)
{
	char	**str_arr;
	int		index;
	t_list	*new_node;

	if (arg[0] == '\0')
		print_error();
	str_arr = ft_split(arg, ' ');
	index = 0;
	if (str_arr == NULL)
		print_error();
	while (str_arr[index] != NULL)
	{
		new_node = (t_list *)malloc(sizeof(t_list));
		if (!new_node)
			print_error();
		new_node->content = check_is_num(str_arr[index]);
		new_node->next = NULL;
		ft_lstadd_back(list, new_node);
		index++;
	}
	clear_str_arr(str_arr);
	check_duplicate(*list);
}

t_list	*parse(int argc, char *argv[])
{
	t_list	*ret;
	int		index;

	ret = NULL;
	index = 1;
	while (index < argc)
	{
		check_is_black(argv[index]);
		split_args(&ret, argv[index]);
		index++;
	}
	return (ret);
}

void	check_duplicate(t_list *list)
{
	t_list	*i;
	t_list	*j;

	i = list;
	while (i->next != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (*(int *)(i->content) == *(int *)(j->content))
				print_error();
			j = j->next;
		}
		i = i->next;
	}
}

void	clear_str_arr(char **str_arr)
{
	int	index;

	index = 0;
	while (str_arr[index])
	{
		free(str_arr[index]);
		index++;
	}
	free(str_arr);
}
