/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:55:05 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/25 21:17:31 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXT_H
# define TEXT_H

# include "gnl.h"

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

typedef struct s_text
{
	char	*textures[4];
	t_color	colors[2][3];
}t_text;

void	init_text(t_text *const text, int const fd);
void	__set_color(t_color *color, char const *str);
char	*__set_texture(char const *str);
int		__init_textures(t_text *const text, char const *str);
t_id	__get_id(char const *str);

size_t	__check_string(char const *str);
t_color	__convert_to_num(char const *str);

#endif
