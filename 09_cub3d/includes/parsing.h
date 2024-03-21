/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:33:15 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/21 23:13:16 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define BUFFER_SIZE 31

typedef enum e_texture_index
{
	E_ER = -2,
	E_NL,
	E_NO,
	E_SO,
	E_WE,
	E_EA,
	E_FL,
	E_CE
}t_index;

typedef struct s_source
{
	int				fd[4];
	unsigned char	color[2][3];
}t_source;

void	__set_textures(char *textures[], char const *const string);
t_index	__identify_type(char const *string);
char	*__get_source(char const *string);

char	*__get_string(int const fd);
int		__is_not_contain(char const *string, char const delimiter);
char	*__merge(char *dest, char const *org);
char	*__extract_string(char const *string, char const delimiter);
void	__separate_string(char *string, char const delimiter);

#endif
