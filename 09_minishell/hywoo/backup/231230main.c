#include "minishell.h"

t_pipe	*init_pipe(t_pipe *pipe)
{
	pipe = malloc(sizeof(t_pipe));
	if (!pipe)
		exit (-1);
	pipe->first = NULL;
	pipe->second = NULL;
	pipe->next = NULL;
	return (pipe);
}

t_command	*init_com(t_command *com)
{
	com = malloc(sizeof(t_command));
	if (!com)
		exit (-1);
	com->redirection = NULL;
	com->simple_command = NULL;
	return (com);
}

t_redirection	*init_redirection(t_redirection *rd)
{
	rd = malloc(sizeof(t_redirection));
	if (!rd)
		exit (-1);
	rd->symbol = NULL;
	rd->file = NULL;
	rd->next = NULL;
	return (rd);
}

t_simple	*make_simple_command(t_token *front, t_command *com)
{
	t_simple	*simple;

	simple = malloc(sizeof(t_simple));
	if (!simple)
		exit (-1);
	if (!front)
		return (simple);
	if (front->type == COMMAND || front->type == WARD)
		simple->command = ft_strdup(front->str);
	else
		return (simple);
	if (front->next)
	{
		if (front->next->type == WARD)
			simple->ward = ft_strdup(front->next->str);
	}
	return (simple);
}

t_token	*add_back_rd(t_token *curr, t_redirection *rd)
{
	t_redirection	*new_rd;

	new_rd = init_redirection(new_rd);
	new_rd->symbol = ft_strdup(curr->str);
	if (!curr->next)
		new_rd->file = ft_strdup("");
	else if (curr->next->type == WARD)
		new_rd->file = ft_strdup(curr->next->str);
	rd->next = new_rd;
	return (curr);
}

t_redirection	*last_redirection(t_redirection *rd)
{
	t_redirection	*last;

	last = rd;
	if (!rd)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

t_redirection	*make_redirection(t_token *front, t_command *com)
{
	t_redirection	*rd;
	t_redirection	*head;
	t_token			*curr;

	curr = front;
	rd = init_redirection(rd);
	head = rd;
	while (curr)
	{
		if (curr->type == REDIRECTION)
		{
			curr = add_back_rd(curr, rd);
			rd = rd->next;
			if (!curr)
				break;
		}
		if (curr->type == PIPE)
			break;
		curr = curr->next;
	}
	rd = head->next;
	free (head);
	return (rd);
}

t_command	*make_command(t_token *front)
{
	t_command		*com;
	t_redirection	*last;

	com = init_com(com);
	com->simple_command = make_simple_command(front, com);
	com->redirection = make_redirection(front, com);
	return (com);
}

t_token	*find_next_front(t_token *front)
{
	while (front)
	{
		front = front->next;
		if (!front)
			break;
		if (front->type == PIPE)
		{
			front = front->next;
			break;
		}
	}
	return (front);
}

t_pipe	*last_pipe(t_pipe *pipe)
{
	t_pipe	*last;

	last = pipe;
	while (last)
	{
		if (!last->next)
			break;
		last = last->next;
	}
	return (last);
}

t_pipe	*new_pipe(t_pipe *pipe, t_token *front)
{
	t_pipe	*new_pipe;

	if (!pipe->first)
	{
		pipe->first = make_command(front);
		return (pipe);
	}
	if (!pipe->second)
	{
		pipe->second = make_command(front);
		return (pipe);
	}
	new_pipe = init_pipe(pipe);
	new_pipe->first = last_pipe(pipe)->second;
	new_pipe->second = make_command(front);
	last_pipe(pipe)->next = new_pipe;
	return (new_pipe);
}

t_pipe	*make_pipe_tree(t_pipe *pipe, t_token *token)
{
	t_token	*front;
	t_token	*curr;
	t_pipe	*next_pipe;
	int		cnt;

	pipe = init_pipe(pipe);
	front = token;
	curr = token;
	next_pipe = pipe;
	cnt = 0;
	while (curr)
	{
		if (curr->type == PIPE)
		{
			curr = curr->next;
			next_pipe = new_pipe(pipe, front);
			front = find_next_front(front);
			cnt++;
			if (!curr)
				break;
		}
		curr = curr->next;
	}
	if (!cnt)
		pipe = new_pipe(pipe, front);
	else
		next_pipe = new_pipe(pipe, front);
	return (pipe);
}

void	test_token(t_token *token)
{
	while (token)
	{
		printf("type:%d + %s\n", token->type, token->str);
		token = token->next;
	}
}

void	test_redirection(t_pipe *pipe, int i)
{
	t_redirection	*rd;

	if (i == 1)
	{
		if (!pipe->first){
			printf("\n");
			return;}
		rd = pipe->first->redirection;
	}
	else if (i == 2)
	{
		if (!pipe->second){
			printf("\n");
			return;}
		rd = pipe->second->redirection;
	}
	while (rd)
	{
		printf("\033[0;33m(rd)\033[0m");
		printf("\033[0;36m%s %s\033[0m", rd->symbol, rd->file);
		rd = rd->next;
	}
	printf("\n");
}

void	test_pipe(t_pipe *pipe)
{
	char	*com1;
	char	*com2;
	char	*first;
	char	*second;
	int		i = 1;

	while (pipe)
	{
		com1 = pipe->first->simple_command->command;
		first = pipe->first->simple_command->ward;
		if (pipe->second)
		{
			com2 = pipe->second->simple_command->command;
			second = pipe->second->simple_command->ward;
		}
		else {
			com2 = NULL;
			second = NULL;
		}
		printf("\033[0;32mPIPE %d: \033[0m", i);
		printf("\033[0;34mfirst\033[0m");
		printf("\033[0;33m(com)\033[0m");
		printf("\033[0;34m%s \033[0m", com1);
		printf("\033[0;33m(ward)\033[0m");
		printf("\033[0;34m%s\033[0m", first);
		test_redirection(pipe, 1);
		printf("\033[0;32m      : \033[0m");
		printf("\033[0;35msecond\033[0m");
		printf("\033[0;33m(com)\033[0m");
		printf("\033[0;35m%s \033[0m", com2);
		printf("\033[0;33m(ward)\033[0m");
		printf("\033[0;35m%s\033[0m", second);
		test_redirection(pipe, 2);
		pipe = pipe->next;
		i++;
	}
}

int	valid_redirection(t_token *curr)
{
	if (curr->type != REDIRECTION)
		return (0);
	if (ft_strlen(curr->str) > 1)
	{
		if (curr->str[0] != curr->str[1])
		{
			printf("syntax error near unexpected token `%c'\n", curr->str[1]);
			return (2);
		}
	}
	if (!curr->next)
	{
		printf("syntax error near unexpected token `newline'\n");
		return (2);
	}
	if (curr->next->type == REDIRECTION || curr->next->type == PIPE)
	{
		printf("syntax error near unexpected token `%s'\n", curr->next->str);
		return (2);
	}
	if (curr->next->type != WARD)
	{
		printf("syntax error near unexpected token `newline'\n");
		return (2);
	}
	return (0);
}

int	valid_pipe(t_token *curr)
{
	int	flag;

	flag = 0;
	if (curr->type != PIPE)
		return (0);
	if (curr->next)
	{
		if (curr->next->type == PIPE)
		{
			printf("bash: syntax error near unexpected token `|'\n");
			return (1);
		}
	}
	else {
		printf("bash: syntax error: unexpected end of file\n");
		return (1);	//input pipe?
	}
	return (0);
}

int	syntax_error(t_token *token)
{
	t_token	*curr;

	curr = token;
	while (curr)
	{
		if (valid_redirection(curr))
			return (1);
		else if (valid_pipe(curr))
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	free_command(t_command *com)
{
	t_redirection	*curr_rd;
	t_redirection	*next_rd;

	if (com->simple_command)
	{
		if (com->simple_command->command)
			free (com->simple_command->command);
		if (com->simple_command->ward)
			free (com->simple_command->ward);
	}
	if (com->redirection)
	{
		curr_rd = com->redirection;
		while (curr_rd)
		{
			next_rd = curr_rd->next;
			if (curr_rd->symbol)
				free(curr_rd->symbol);
			if (curr_rd->file)
				free(curr_rd->file);
			free (curr_rd);
			curr_rd = next_rd;
		}
	}
}

void	all_free(t_token *token, t_pipe *pipe)
{
	t_token	*token_next;
	t_pipe	*pipe_next;

	token_next = token;
	pipe_next = pipe;
	if (token)
	{
		while (token)
		{
			token_next = token->next;
			if (token->str)
				free(token->str);
			free(token);
			token = token_next;
		}
	}
	if (pipe)
	{
		while (pipe)
		{
			pipe_next = pipe->next;
			if (pipe->first)
				free_command(pipe->first);
			if (pipe->second)
				free_command(pipe->second);
			free (pipe);
			pipe = pipe_next;
		}
	}
}

void	ft_parsing(char *str)
{
	t_token	*token;
	t_pipe	*pipe_tree;

	if (valid_quotes(str))
		return ;
	token = init_token(token);
	tokenizer(token, str);
	if (syntax_error(token))
	{
		all_free(token, pipe_tree);
		return ;
	}
	pipe_tree = make_pipe_tree(pipe_tree, token->next);
	// test_token(token);
	test_pipe(pipe_tree);
	all_free(token, pipe_tree);
}

void	ft_readline(void)
{
	char	*str;

	while (1)
	{
		str = readline("minishell$ ");
		if (str && !*str)
		{
			free (str);
			str = NULL;
		}
		else if (str)
		{
			add_history(str);
			ft_parsing(str);
			free (str);
			str = NULL;
		}
		else if (!str)
		{
			printf("\033[1A");
			printf("\033[10C");
			printf(" exit\n");
			exit(-1);
		}
		else if (*str == '\0')
			free (str);
	}
}

int	main(int ac, char **av, char *envp[])
{
	if (ac != 1)
	{
		printf("error\n");
		return (2);
	}
	ft_signal();
	ft_readline();
	return (0);
}
