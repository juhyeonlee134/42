/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:43:32 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/28 15:03:43 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>

# define BUFF_SZ 31

enum e_error
{
	E_ALLOC,
	E_ARG_LACK,
	E_ARG_MANY,
	E_FILE_INVAL,
	E_FILE_FDERR,
	E_RSRC_LACK,
	E_TYPE_INVAL,
	E_TEXT_NOTFD,
	E_TEXT_MANY,
	E_COL_NOTFD,
	E_COL_LACK,
	E_COL_MANY,
	E_COL_INVAL,
	E_MAP_NOTFD,
	E_MAP_INVAL,
	E_MAP_2PLAYER,
	E_MAP_NOPLAYER
};

typedef enum e_type
{
	T_NL = -1,
	T_NO,
	T_SO,
	T_WE,
	T_EA,
	T_FL,
	T_CL
}t_type;

typedef unsigned char	t_color;
typedef struct s_resource
{
	char	*textures[4];
	t_color	colors[2][3];
}t_rsrc;
typedef struct s_map
{
	char	**map;
	size_t	h;
	size_t	w;
}t_map;

void	print_error(enum e_error num);
void	resrouce_error(enum e_error num);
void	map_error(enum e_error num);

char	*get_line(int const fd);
int		not_contain_nl(char const *str);
char	*merge(char *const s1, char const *const s2);
char	*extract(char const *const str);
void	organize(char *const str);

int		open_file(char const *const file_name);

void	init_resource(t_rsrc *const rsrc, int const fd);
void	clear_resrouce(t_rsrc *const rsrc);
t_type	get_type(char const *str);
int		is_white(char const ch);
char	*set_texture(char const *str);
void	set_color(t_color *const color, char const *str);
t_color	convert_color(char const *const str);

void	init_map(t_map *const map, int const fd);
size_t	get_start_point(char const *str);
void	clear_map(t_map const map);
void	get_map_size(t_map *const map, char const *str);
void	convert_map(t_map *const map, char const *str);
size_t	get_line_len(char const *str);

void	check_elements(t_map const *const map);
int		check_player(char const el);
void	check_surround(t_map const *const map);
void	find_player(t_map const map, size_t *const y, size_t *const x);
void	copy_map(t_map *const dst, t_map const org);

#endif
