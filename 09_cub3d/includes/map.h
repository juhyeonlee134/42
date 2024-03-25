/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:20:45 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/25 21:52:16 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "gnl.h"

typedef struct s_map
{
	char	**map;
	size_t	h;
	size_t	w;
}t_map;

void	init_map(t_map *const map, int const fd);
void	__init_map_size(char const *map_str, size_t *h, size_t *w);
void	__init_map_context(t_map *const map, char const *map_str);
void	__full_blank(char *const map, size_t const w);
size_t	__get_line_len(char const *str);

void	__check_map(t_map map);

void	clear_map(t_map *const map);

#endif
