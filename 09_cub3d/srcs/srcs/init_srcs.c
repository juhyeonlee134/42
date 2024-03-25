/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_srcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:43:18 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/25 21:46:43 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"
#include <fcntl.h>
#include <stdio.h>

void	*init_sources(t_srcs *const srcs, char const *const f_name)
{
	int const	fd = __open_file(f_name);

	if (fd < 0)
	{
		perror("not found file");
		exit(EXIT_FAILURE);
	}
	init_text(&(srcs->text), fd);
	init_map(&(srcs->map), fd);
	return (NULL);
}

int	__open_file(char const *file_name)
{
	size_t const	len = ft_strlen(file_name);

	if (ft_strncmp(file_name + (len - 4), ".cub", 4) != 0)
	{
		perror("incorrect file");
		exit(EXIT_FAILURE);
	}
	return (open(file_name, O_RDONLY));
}
