/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:14:08 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/28 12:51:33 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	int		fd;
	t_rsrc	rsrc;

	if (argc < 2)
		print_error(E_NOFILE);
	else if (argc > 2)
		print_error(E_ARGNUM);
	fd = open_file(argv[1]);
	init_resource(&rsrc, fd);
	printf("NO : %s\nSO : %s\nWE : %s\nEA : %s\n", \
			rsrc.textures[0], rsrc.textures[1], rsrc.textures[2], \
			rsrc.textures[3]);
	printf("FL : %d %d %d\n", \
			rsrc.colors[0][0], rsrc.colors[0][1], rsrc.colors[0][2]);
	printf("CL : %d %d %d\n", \
			rsrc.colors[1][0], rsrc.colors[1][1], rsrc.colors[1][2]);
	return (0);
}
