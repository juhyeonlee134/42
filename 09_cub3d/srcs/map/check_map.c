/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:52:34 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/25 21:53:24 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	clear_map(t_map *const map)
{
	size_t	idx;

	idx = 0;
	while (idx < map->h)
	{
		free(map->map[idx]);
		idx++;
	}
	free(map->map);
}
