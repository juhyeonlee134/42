/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:43:45 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/12 23:14:11 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!parse(argc, (const char **)argv, &data))
		return (0);
	return (0);
}
