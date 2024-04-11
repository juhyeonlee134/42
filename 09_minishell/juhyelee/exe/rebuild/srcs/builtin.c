/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:12:21 by juhyelee          #+#    #+#             */
/*   Updated: 2024/01/17 19:48:34 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtin(const char *cmd)
{
	if (ft_strncmp(cmd, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "export", 7) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(cmd, "env", 3) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", 5) == 0)
		return (1);
	return (0);
}

void	builtin(const t_proc proc, t_exe *exe)
{
	if (ft_strncmp(proc.cmd, "echo", 5) == 0)
		exe->st_exit = execute_echo(proc, exe->st_exit);
	else if (ft_strncmp(proc.cmd, "cd", 3) == 0)
		exe->st_exit = execute_cd(proc.arg, exe->env);
	else if (ft_strncmp(proc.cmd, "pwd", 4) == 0)
		exe->st_exit = execute_pwd(proc);
	else if (ft_strncmp(proc.cmd, "export", 7) == 0)
		exe->st_exit = execute_export(proc, exe->env);
	else if (ft_strncmp(proc.cmd, "unset", 6) == 0)
		exe->st_exit = execute_unset(proc.arg, exe->env);
	else if (ft_strncmp(proc.cmd, "env", 4) == 0)
		exe->st_exit = execute_env(proc, (const t_envp *)(*exe->env));
	else if (ft_strncmp(proc.cmd, "exit", 5) == 0)
		exe->st_exit = execute_exit(proc.arg);
	else
		exe->st_exit = EXIT_FAILURE;
}

int	execute_pwd(const t_proc proc)
{
	pid_t	child;
	int		exit_num;
	char	buffer[2024];
	char	*ret;

	child = fork();
	if (child < 0)
		exit(EXIT_FAILURE);
	else if (child == 0)
	{
		ret = getcwd(buffer, 2024);
		if (!ret)
			return (EXIT_FAILURE);
		ft_putendl_fd(buffer, proc.output);
		exit(EXIT_SUCCESS);
	}
	waitpid(child, &exit_num, 0);
	return (WEXITSTATUS(exit_num));
}

int	execute_env(const t_proc proc, const t_envp *list)
{
	pid_t	child;
	int		exit_num;

	child = fork();
	if (child < 0)
		exit(EXIT_FAILURE);
	else if (child == 0)
	{
		while (list)
		{
			if (list->value && list->value[0])
			{
				ft_putstr_fd(list->variable, proc.output);
				ft_putchar_fd('=', proc.output);
				ft_putendl_fd(list->value, proc.output);
			}
			list = list->next;
		}
		exit(EXIT_SUCCESS);
	}
	waitpid(child, &exit_num, 0);
	return (WEXITSTATUS(exit_num));
}

int	is_exist(const t_list *files, const char *file_name)
{
	t_file	*content;

	while (files)
	{
		content = files->content;
		if (ft_strncmp(content->name, file_name, \
					ft_strlen(content->name) + 1) == 0)
			return (1);
		files = files->next;
	}
	return (0);
}
