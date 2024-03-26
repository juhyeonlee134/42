/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:37:25 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/26 21:32:52 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include <stdio.h>
# define BUFFER_SIZE 31

typedef enum e_id
{
	E_ER = -2,
	E_NL,
	E_NO,
	E_SO,
	E_WE,
	E_EA,
	E_FL,
	E_CE
}t_id;

typedef unsigned char	t_color;

typedef struct s_map
{
	char	*textures[4];
	t_color	colors[2][3];
	char	**map;
	size_t	h;
	size_t	w;
}t_map;

void	init_map(t_map *const map, char const *const file_name);
int		__open_file(char const *file_name);
void	clear_map(t_map *const map);

void	__init_map_info(t_map *const map, int const fd);
void	__set_color(t_color *color, char const *str);
char	*__set_textures(char const *str);
int		__init_textures(t_map *const map, char const *str);
t_id	__get_id(char const *str);
size_t	__check_string(char const *str);
t_color	__convert_to_num(char const *str);

void	__init_map(t_map *const map, int const fd);
size_t	__get_height(char const *str);
size_t	__get_width(char const *const str);
size_t	__get_line_len(char const *str);
void	__init_map_context(t_map *const map, char const *str);
void	__full_blank(char *const map, size_t const w);

void	__check_map(t_map const map);
void	__check_element(t_map const map);
void	__check_one_line(char const *str);
void	__go_to_wall(t_map const map, size_t *const h, size_t *const w);
void	__check_surround(t_map map, size_t const h, size_t const w);
void	__walk_down(t_map *const map, size_t const h, size_t const w, \
		char const del);
void	__walk_left(t_map *const map, size_t const h, size_t const w, \
		char const del);
void	__walk_right(t_map *const map, size_t const h, size_t const w, \
		char const del);
void	__walk_up(t_map *const map, size_t const h, size_t const w, \
		char const del);

char	*get_next_line(int const fd);
char	*__merge(char *dst, char const *org);
char	*__extract_string(char const *str, char const del);
void	__separate_string(char *str, char const del);
int		__is_not_contain(char const *str, char const del);

#endif
