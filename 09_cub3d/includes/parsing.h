/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:51:36 by juhyelee          #+#    #+#             */
/*   Updated: 2023/09/08 20:49:46 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include "get_next_line.h"
# include "utils.h"
# include <fcntl.h>

typedef struct s_info
{
	char	**map;
	int		width;
	int		height;
	t_pos	player;
	size_t	e_num;
	size_t	c_num;
}t_info;

typedef struct s_num
{
	size_t	player;
	size_t	exit;
	size_t	coin;
}t_num;

char	**parse(const char *file);

int		get_fd(const char *file);
char	**get_map(const int fd, const char *file);
int		is_valid(const char **map);
void	remove_map(char **map);

int		get_height_by_file(const char *file);
void	set_map(const int fd, const size_t height, char **map);
void	set_line(char *line);

int		is_valid_map(const char **map);
int		is_valid_root(const char **map);

int		is_rectangle(const char **map);
int		is_wall_arround(const char **map);
int		is_all_one(const char *line);
int		is_contain(const char **map);

void	dup_map(t_info *info, const char **map);
void	check_element(const char **map, size_t *e_num, size_t *c_num);
void	clear_map(char **map, const size_t index);
size_t	get_height_by_map(const char **map);

void	found_player_pos(t_info *info);
void	check_all_path(t_info *info, const int x, const int y);

int		check_path(t_info *info, const int x, const int y);

#endif
