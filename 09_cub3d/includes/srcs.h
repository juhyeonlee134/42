/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:33:15 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/25 21:37:22 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H

# include "map.h"
# include "text.h"

typedef struct s_srcs
{
	t_text	text;
	t_map	map;
}t_srcs;

void	*init_sources(t_srcs *const srcs, char const *const f_name);
int		__open_file(char const *const f_name);

#endif
