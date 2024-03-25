/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:13:57 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/25 21:46:13 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "text.h"
#include <stdio.h>

size_t	__check_string(char const *str)
{
	size_t	cnt;
	size_t	check;

	cnt = 0;
	while (str[cnt] && str[cnt] != ' ')
		cnt++;
	if (str[cnt] == '\0')
	{
		perror("invalid file");
		exit(EXIT_FAILURE);
	}
	cnt++;
	check = cnt;
	while (str[check])
	{
		if (str[check] == ' ')
		{
			perror("invalid file");
			exit(EXIT_FAILURE);
		}
		check++;
	}
	return (cnt);
}

t_color	__convert_to_num(char const *str)
{
	t_color const	ret_num = ft_atoi(str);
	char			*ret_str;

	ret_str = ft_itoa(ret_num);
	if (str[0] == '+' || (str[0] == '-' && str[1] == '0'))
		str++;
	if (ft_strncmp(str, ret_str, ft_strlen(ret_str)) != 0)
	{
		perror("invalid file");
		exit(EXIT_FAILURE);
	}
	free(ret_str);
	return (ret_num);
}
