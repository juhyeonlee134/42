/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:43:32 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/28 13:20:27 by juhyelee         ###   ########.fr       */
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
	E_NOFILE,
	E_ARGNUM,
	E_INVFILE,
	E_FDERR,
	E_LACKINFO,
	E_INVTYPE,
	E_NOTXT,
	E_MANYTXT,
	E_NOCOL,
	E_LACKCOL,
	E_MANYCOL,
	E_INVCOL
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

char	*get_line(int const fd);
int		not_contain_nl(char const *str);
char	*merge(char *const s1, char const *const s2);
char	*extract(char const *const str);
void	organize(char *const str);

int		open_file(char const *const file_name);

void	init_resource(t_rsrc *const rsrc, int const fd);
t_type	get_type(char const *str);
int		is_white(char const ch);
char	*set_texture(char const *str);
void	set_color(t_color *const color, char const *str);
t_color	convert_color(char const *const str);

#endif
