/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:21:32 by taeoh             #+#    #+#             */
/*   Updated: 2024/04/19 10:24:24 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static double	dabs(double a)
{
	return ((a >= 0) * a - (a < 0) * a);
}

int	draw_player(t_game *const game, int x, int y)
{
	double	doffx;
	double	doffy;

	doffx = (game->posx + (-1) * game->mmap_grid / 2 \
	+ game->mmap_grid / game->mmap_size * x);
	doffy = (game->posy + (-1) * game->mmap_grid / 2 \
	+ game->mmap_grid / game->mmap_size * y);
	return ((dabs(game->posx - doffx) <= game->mmap_pdot) \
	&& (dabs(game->posy - doffy) <= game->mmap_pdot));
}

void	draw_minimap(t_game *const game, int x, int y)
{
	int		offx;
	int		offy;
	char	*addr;

	while (++y < game->mmap_size)
	{
		x = -1;
		while (++x < game->mmap_size)
		{
			offx = get_offset(*game, game->posx, x);
			offy = get_offset(*game, game->posy, y);
			addr = get_addr(game->minimap, y, x);
			if (draw_player(game, x, y))
				*(unsigned int *)addr = 0xDD0000;
			else if (offx >= 0 && offy >= 0 && offx < (int)game->map.w && \
			offy < (int)game->map.h && game->map.map[offy][offx] == '1')
				*(unsigned int *)addr = 0x333333 | game->map_opacity;
			else if (offx >= 0 && offy >= 0 && offx < (int)game->map.w && \
			offy < (int)game->map.h && (game->map.map[offy][offx] == 'D' || \
			game->map.map[offy][offx] == 'O'))
				*(unsigned int *)addr = 0xAAAAAA | game->map_opacity;
			else
				*(unsigned int *)addr = 0xFFFFFF | game->map_opacity;
		}
	}
}

int	get_offset(t_game const game, double pos, int n)
{
	return ((int)(pos + (-1) * game.mmap_grid / 2 + \
	game.mmap_grid / game.mmap_size * n));
}

void	put_minimap(t_game *const game)
{
	game->mmap_size = HEIGHT / 5;
	game->mmap_pos = HEIGHT / 50;
	game->mmap_grid = 9;
	game->mmap_pdot = 0.15;
	game->map_opacity = 0xDD000000;
	game->minimap.obj = mlx_new_image(game->mlx, game->mmap_size, \
	game->mmap_size);
	if (game->minimap.obj == NULL)
		print_error(E_XPM_FAIL);
	game->minimap.addr = mlx_get_data_addr(game->minimap.obj, \
	&game->minimap.bpp, &game->minimap.len, &game->minimap.endian);
	draw_minimap(game, -1, -1);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap.obj, \
	game->mmap_pos, game->mmap_pos);
}
