/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:07:00 by juhyelee          #+#    #+#             */
/*   Updated: 2023/09/08 20:13:09 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	init(const char *file, t_game **game)
{
	char	**map;

	map = parse(file);
	if (!map)
		return (0);
	*game = make_game((const char **)map);
	if (!*game)
	{
		remove_map(map);
		print_error(FAILED_MALLOC);
		return (0);
	}
	init_window((*game)->window, (const char **)map);
	if (!set_sprites((*game)->window, (*game)->sprites))
	{
		remove_map(map);
		remove_game(*game);
		print_error(NO_SUCH_FILE);
		return (0);
	}
	set_game(*game);
	return (1);
}

void	loop(t_game *game)
{
	draw_window(game);
	mlx_key_hook(game->window->win, press_key, game);
	mlx_hook(game->window->win, WIN_CLOSE, 0, finish, game);
	mlx_loop(game->window->mlx);
}

t_game	*make_game(const char **map)
{
	unsigned char	flag;
	t_game			*game;

	flag = 0;
	game = (t_game *)malloc(sizeof(t_game));
	if (game)
	{
		game->map = (char **)map;
		game->window = make_window();
		if (game->window)
			flag |= WINDOW;
		game->sprites = make_sprites();
		if (game->sprites)
			flag |= SPRITES;
		game->player = make_pos();
		if (game->player)
			flag |= PLAYER;
		game->exit = make_pos();
		if (game->exit)
			flag |= EXIT;
		game->coin_num = 0;
		clean_game(game, flag);
	}
	return (game);
}

void	set_game(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->coin_num++;
			else if (game->map[y][x] == 'P')
				set_pos(game->player, x, y);
			else if (game->map[y][x] == 'E')
				set_pos(game->exit, x, y);
			x++;
		}
		y++;
	}
}

void	clean_game(t_game *game, const unsigned char flag)
{
	if (flag == ALL_EXISTS)
		return ;
	if (flag & WINDOW)
		free(game->window);
	if (flag & SPRITES)
		free(game->sprites);
	if (flag & PLAYER)
		free(game->player);
	if (flag & EXIT)
		free(game->exit);
	free(game);
}
