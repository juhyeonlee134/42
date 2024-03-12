/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 00:09:02 by juhyelee          #+#    #+#             */
/*   Updated: 2023/09/08 20:58:59 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "utils.h"
# include "parsing.h"
# define BACK_COLOR 0xF7D8A5
# define FONT_COLOR 0xFFFFFF
# define WIN_CLOSE 17

enum e_flag{
	WINDOW = 1<<0,
	SPRITES = 1<<1,
	PLAYER = 1<<2,
	EXIT = 1<<3,
	ALL_EXISTS = 0xF
};

enum e_key {
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_ESC = 53
};

typedef struct s_game
{
	char		**map;
	t_window	*window;
	t_sprites	*sprites;
	t_pos		*player;
	t_pos		*exit;
	int			coin_num;
}t_game;

int		init(const char *file, t_game **game);
void	loop(t_game *game);

t_game	*make_game(const char **map);
void	set_game(t_game *game);

void	clean_game(t_game *game, const unsigned char flag);

void	draw_window(t_game *game);
int		press_key(int key, t_game *game);
int		finish(t_game *game);

void	draw_line(t_game *game, const char *line, const int y);
void	draw_player(t_game *game, const int x, const int y);

void	move(t_game *game, const int x, const int y);
void	check_obj(t_game *game, const int x, const int y);

void	remove_game(t_game *game);

#endif
