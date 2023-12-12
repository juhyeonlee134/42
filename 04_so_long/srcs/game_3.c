/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 01:25:06 by juhyelee          #+#    #+#             */
/*   Updated: 2023/09/08 20:14:06 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "ft_printf.h"

void	draw_line(t_game *game, const char *line, const int y)
{
	int	x;

	x = 0;
	while (*line)
	{
		mlx_put_image_to_window(game->window->mlx, game->window->win, \
				game->sprites->space, x, y);
		if (*line == '1')
			mlx_put_image_to_window(game->window->mlx, game->window->win, \
					game->sprites->wall, x, y);
		else if (*line == 'E')
			mlx_put_image_to_window(game->window->mlx, game->window->win, \
					game->sprites->exit, x, y);
		else if (*line == 'C')
			mlx_put_image_to_window(game->window->mlx, game->window->win, \
					game->sprites->coin, x, y);
		else if (*line == 'P')
			draw_player(game, x, y);
		line++;
		x += OBJ_SIZE;
	}
}

void	draw_player(t_game *game, const int x, const int y)
{
	mlx_put_image_to_window(game->window->mlx, game->window->win, \
			game->sprites->player, x, y);
	game->player->x = x / OBJ_SIZE;
	game->player->y = y / OBJ_SIZE;
}

void	move(t_game *game, const int x, const int y)
{
	static int	movement;
	int			to_x;
	int			to_y;

	to_x = game->player->x + x;
	to_y = game->player->y + y;
	if (game->map[to_y][to_x] != '1')
	{
		movement++;
		check_obj(game, to_x, to_y);
		game->map[to_y][to_x] = 'P';
		if (is_same_pos(game->player, game->exit))
			game->map[game->player->y][game->player->x] = 'E';
		else
			game->map[game->player->y][game->player->x] = '0';
		ft_printf("movement : %d\n", movement);
		draw_window(game);
	}
}

void	check_obj(t_game *game, const int x, const int y)
{
	if (game->map[y][x] == 'C')
		game->coin_num--;
	else if (game->exit->x == x && game->exit->y == y && game->coin_num == 0)
		finish(game);
	else if (game->map[y][x] == 'R')
		finish(game);
}
