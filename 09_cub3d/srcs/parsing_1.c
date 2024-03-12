/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:52:43 by juhyelee          #+#    #+#             */
/*   Updated: 2023/09/08 19:53:57 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**parse(const char *file)
{
	int		fd;
	char	**map;

	fd = get_fd(file);
	if (fd < 0)
	{
		print_error(BAD_FILE_DESCRIPTOR);
		return (NULL);
	}
	map = get_map(fd, file);
	close(fd);
	if (!map)
	{
		print_error(FAILED_MALLOC);
		return (NULL);
	}
	if (!is_valid((const char **)map))
	{
		print_error(INVALIED_FILE);
		remove_map(map);
		return (NULL);
	}
	return (map);
}

int	get_fd(const char *file)
{
	int	index;

	index = ft_strlen(file) - 1;
	if (file[index] != 'r')
		return (-1);
	index--;
	if (file[index] != 'e')
		return (-1);
	index--;
	if (file[index] != 'b')
		return (-1);
	index--;
	if (file[index] != '.')
		return (-1);
	return (open(file, O_RDONLY));
}

int	is_valid(const char **map)
{
	if (!is_valid_map(map))
		return (0);
	if (!is_valid_root(map))
		return (0);
	return (1);
}

void	remove_map(char **map)
{
	size_t	index;

	index = 0;
	while (map[index])
	{
		free(map[index]);
		index++;
	}
	free(map[index]);
	free(map);
}
