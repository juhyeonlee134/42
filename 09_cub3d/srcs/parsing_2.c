/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 22:23:22 by juhyelee          #+#    #+#             */
/*   Updated: 2023/09/08 20:54:19 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**get_map(const int fd, const char *file)
{
	int		height;
	char	**map;

	height = get_height_by_file(file);
	map = NULL;
	if (height < 0)
	{
		print_error(BAD_FILE_DESCRIPTOR);
		return (NULL);
	}
	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (map)
		set_map(fd, height + 1, map);
	return (map);
}

int	get_height_by_file(const char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	set_map(const int fd, const size_t height, char **map)
{
	size_t	index;
	char	*line;

	index = 0;
	while (index < height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		set_line(line);
		map[index] = ft_strdup(line);
		free(line);
		index++;
	}
	map[index] = NULL;
}

void	set_line(char *line)
{
	while (*line && *line != '\n')
		line++;
	if (*line == '\n')
		*line = '\0';
}
