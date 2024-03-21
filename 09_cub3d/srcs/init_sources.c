/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sources.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:29:51 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/22 00:14:13 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_sources(t_sources *const sources, char const *file)
{
	int const	fd = __get_file_descriptor(file);
	char		*string;
	char		*textures[6];

	if (fd < 0)
	{
		perror("Not found file\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		string = __get_string(fd);
		if (!string)
			break ;
		__set_textures(textures, string);
		free(string);
	}
	sources->textures[0] = textures[0];
	sources->textures[1] = textures[1];
	sources->textures[2] = textures[2];
	sources->textures[3] = textures[3];
	__set_colors(sources->colors[0], textures[4]);
	__set_colors(sources->colors[1], textures[5]);
}

int	__get_file_descriptor(char const *file)
{
	size_t	file_len = ft_strlen(file);

	if (ft_strncmp(file + (file_len - 4), ".cub", 4) != 0)
	{
		perror("Invlid file\n");
		exit(EXIT_FAILURE);
	}
	return (open(file, O_RDONLY));
}

void	__set_colors(unsigned char *colors, char const *const string)
{
	char **color_string;

	color_string = ft_split(string, ',');
	if (!color_string)
		exit(EXIT_FAILURE);
	colors[0] = ft_atoi(color_string[0]);
	colors[1] = ft_atoi(color_string[1]);
	colors[2] = ft_atoi(color_string[2]);
	free(color_string[0]);
	free(color_string[1]);
	free(color_string[2]);
	free(color_string);
}
