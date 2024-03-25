/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:33:15 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/25 18:25:06 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
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
	size_t	map_w;
	size_t	map_h;
}t_map;

void	init_map(t_map *const map, char const *const file_name);
int		__open_file(char const *file_name);
void	__init_sources(t_map *const map, int const fd);
void	__init_map(t_map *const map, int const fd);

int		__set_sources(t_map *const map, char const *string);
t_id	__get_id(char const *string);
char	*__set_texture(char const *string);
size_t	__check_string(char const *string);

void	__set_color(unsigned char *color, char const *string);
t_color	__convert_to_num(char const *string);

void	__set_map(t_map *const map, char const *map_string);
void	__set_map_size(char const *map_string, size_t *h, size_t *w);
size_t	__get_line_len(char const *string);
void	__full_blank(char *map, size_t const w);

char	*__get_string(int const fd);
int		__is_not_contain(char const *string, char const delimiter);
char	*__merge(char *dest, char const *org);
char	*__extract_string(char const *string, char const delimiter);
void	__separate_string(char *string, char const delimiter);

#endif
