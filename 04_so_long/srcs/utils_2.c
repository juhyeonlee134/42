/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 23:50:21 by juhyelee          #+#    #+#             */
/*   Updated: 2023/09/08 19:39:54 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	get_height(const char **map);

t_window	*make_window(void)
{
	return ((t_window *)malloc(sizeof(t_window)));
}

void	init_window(t_window *window, const char **map)
{
	window->mlx = mlx_init();
	window->width = ft_strlen(map[0]) * OBJ_SIZE;
	window->height = get_height(map) * OBJ_SIZE;
	window->win = mlx_new_window(window->mlx, window->width, window->height, \
			"so_long");
}

static size_t	get_height(const char **map)
{
	size_t	index;

	index = 0;
	while (map[index])
		index++;
	return (index);
}

t_sprites	*make_sprites(void)
{
	return ((t_sprites *)malloc(sizeof(t_sprites)));
}

int	set_sprites(const t_window *window, t_sprites *sprites)
{
	int	width;
	int	height;

	sprites->player = mlx_xpm_file_to_image(window->mlx, \
			"textures/player.xpm", &width, &height);
	sprites->space = mlx_xpm_file_to_image(window->mlx, \
			"textures/space.xpm", &width, &height);
	sprites->wall = mlx_xpm_file_to_image(window->mlx, \
			"textures/wall.xpm", &width, &height);
	sprites->coin = mlx_xpm_file_to_image(window->mlx, \
			"textures/collectible.xpm", &width, &height);
	sprites->exit = mlx_xpm_file_to_image(window->mlx, \
			"textures/exit.xpm", &width, &height);
	if (!sprites->player || !sprites->wall || !sprites->coin || \
		!sprites->exit || !sprites->space)
		return (0);
	return (1);
}
