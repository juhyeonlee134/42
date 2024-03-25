/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:29:06 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/25 20:34:46 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft.h"
# define BUFFER_SIZE 31

char	*get_next_line(int const fd);
char	*__merge(char *dst, char const *org);
char	*__extract_string(char const *str, char const del);
void	__separate_string(char *str, char const del);
int		__is_not_contain(char const *str, char const del);

#endif
