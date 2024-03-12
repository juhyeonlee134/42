/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:20:45 by juhyelee          #+#    #+#             */
/*   Updated: 2023/09/08 19:39:35 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include <string.h>
# define OBJ_SIZE 64;

enum e_errnum{
	NO_SUCH_FILE = 2,
	ARGS_LIST_TOO_LONG = 7,
	BAD_FILE_DESCRIPTOR = 9,
	FAILED_MALLOC = 12,
	INVALIED_FILE = 22
};

typedef struct s_pos
{
	int	x;
	int	y;
}t_pos;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	size_t	width;
	size_t	height;
}t_window;

typedef struct s_sprites
{
	void	*player;
	void	*space;
	void	*wall;
	void	*coin;
	void	*exit;
}t_sprites;

void		print_error(enum e_errnum errnum);

t_pos		*make_pos(void);
void		set_pos(t_pos *pos, const int x, const int y);
int			is_same_pos(t_pos *p1, t_pos *p2);

t_window	*make_window(void);
void		init_window(t_window *window, const char **map);

t_sprites	*make_sprites(void);
int			set_sprites(const t_window *window, t_sprites *sprites);

#endif
