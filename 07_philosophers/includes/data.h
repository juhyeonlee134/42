/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:57:44 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/12 23:16:31 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <unistd.h>

typedef struct s_data
{
	size_t	size;
	size_t	cnt;
	size_t	dead;
	size_t	eating;
	size_t	sleeping;
}t_data;

int		parse(const size_t argc, const char *argv[], t_data *data);
int		is_invalid(const t_data);
void	print_error(const char *message);
size_t	convert_to_num(const char *str);

#endif
