/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:14:08 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/28 15:04:30 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	int		fd;
	t_rsrc	rsrc;
	t_map	map;

	if (argc < 2)
		print_error(E_ARG_LACK);
	else if (argc > 2)
		print_error(E_ARG_MANY);
	fd = open_file(argv[1]);
	init_resource(&rsrc, fd);
	printf("NO : %s\nSO : %s\nWE : %s\nEA : %s\n", \
			rsrc.textures[0], rsrc.textures[1], rsrc.textures[2], \
			rsrc.textures[3]);
	printf("FL : %d %d %d\n", \
			rsrc.colors[0][0], rsrc.colors[0][1], rsrc.colors[0][2]);
	printf("CL : %d %d %d\n", \
			rsrc.colors[1][0], rsrc.colors[1][1], rsrc.colors[1][2]);
	init_map(&map, fd);
	for (size_t index = 0; index < map.h; index++)
		puts(map.map[index]);
	clear_resrouce(&rsrc);
	clear_map(map);
	close(fd);
	return (0);
}

int	open_file(char const *const file_name)
{
	size_t const	len = ft_strlen(file_name);
	int				fd;

	if (len < 4)
		print_error(E_FILE_INVAL);
	if (ft_strncmp(file_name + (len - 4), ".cub", 4) != 0)
		print_error(E_FILE_INVAL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_error(E_FILE_FDERR);
	return (fd);
}

int	is_white(char const ch)
{
	return (ch == ' ' || (ch >= 9 && ch <= 13));
}

void	clear_resrouce(t_rsrc *const rsrc)
{
	free(rsrc->textures[0]);
	free(rsrc->textures[1]);
	free(rsrc->textures[2]);
	free(rsrc->textures[3]);
}

void	clear_map(t_map const map)
{
	size_t	index;

	index = 0;
	while (index < map.h)
	{
		free(map.map[index]);
		index++;
	}
	free(map.map);
}
