/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 00:11:48 by juhyelee          #+#    #+#             */
/*   Updated: 2023/09/08 21:06:44 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	draw_window(t_game *game)
{
	size_t	index;
	int		y;

	mlx_clear_window(game->window->mlx, game->window->win);
	index = 0;
	y = 0;
	while (game->map[index])
	{
		draw_line(game, (const char *)(game->map[index]), y);
		index++;
		y += OBJ_SIZE;
	}
}

int	press_key(int key, t_game *game)
{
	if (key == KEY_A)
		move(game, -1, 0);
	else if (key == KEY_S)
		move(game, 0, 1);
	else if (key == KEY_D)
		move(game, 1, 0);
	else if (key == KEY_W)
		move(game, 0, -1);
	else if (key == KEY_ESC)
		finish(game);
	return (1);
}

int	finish(t_game *game)
{
	remove_map(game->map);
	remove_game(game);
	exit(0);
}

void	remove_game(t_game *game)
{
	free(game->window);
	free(game->sprites);
	free(game->player);
	free(game->exit);
	free(game);
}
