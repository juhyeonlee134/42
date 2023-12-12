/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:29:00 by juhyelee          #+#    #+#             */
/*   Updated: 2023/11/09 15:12:57 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "parse.h"

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	t_list		*parsing;

	if (argc < 2)
		print_error();
	parsing = parse(argc, argv);
	stacks.a = indexing(&parsing);
	check_sorting(stacks.a);
	stacks.b = init_stack();
	empty_ins_cnt(&stacks.ins);
	sort(&stacks);
	clear_stack(stacks.a);
	clear_stack(stacks.b);
	exit(0);
}

void	print_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(0);
}
