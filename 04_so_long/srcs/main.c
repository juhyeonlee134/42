/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 23:01:39 by juhyelee          #+#    #+#             */
/*   Updated: 2023/09/08 21:06:49 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "game.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc == 2)
	{
		game = NULL;
		if (init(argv[1], &game))
			loop(game);
	}
	else if (argc > 2)
		print_error(ARGS_LIST_TOO_LONG);
	else
		print_error(INVALIED_FILE);
	return (0);
}
