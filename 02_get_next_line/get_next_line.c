#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*curr;
	char			*ret;
	char			buffer[BUFFER_SIZE];
	int				read_ret;

	curr = find_fd((const t_list *)list, fd);
	if (!curr)
		curr = add_fd(&list, fd);
	if (!curr)
		return (NULL);
	while (get_output(curr, ret))
	{
		read_ret = read_buffer(curr, ret,  buffer);
		if (read_ret < 0)
			return (NULL);
		if (read_ret == 0)
			return (ret);
	}
	return (ret);
}

int	get_output(t_list *curr, char *ret)
{
	size_t	index;
	int		is_newline;

	if (curr->remain == NULL)
		return (1);
	index = 0;
	is_newline = 0;
	while (curr->remain[index])
	{
		if (curr->remain[index] == '\n')
		{
			is_newline = 1;
			break ;
		}
		index++;
	}
	if (!is_newline)
		return (1);
	ret = duplicate(curr->remain, '\n');
	push_to_front(curr->remain, index);
	return (0);
}

int	read_buffer(t_list *curr, char *ret, char *buffer)
{
	int	read_ret;

	read_ret = read(curr->fd, buffer, BUFFER_SIZE);
	if (read_ret < 0)
		return (-1);
	if (read_ret == 0)
	{
		ret = duplicate(curr->remain)
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		free(curr->remain);
		free(curr);
		return (0);
	}
	merge(remain, buffer);
	return (1);
}

t_list	*find_fd(const t_list *list, const int fd)
{
	while (list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_list	*add_fd(t_list **list, const int fd)
{
	t_list	*new_fd;

	new_fd = (t_list *)malloc(sizeof(t_list));
	if (!new_fd)
		return (NULL);
	new_fd->fd = fd;
	new_fd->remain = NULL;
	new_fd->next = NULL;
	if (!*list)
	{
		new_fd->prev = new_fd;
		*list = new_fd;
	}
	else
	{
		new_fd->prev = *list->prev;
		*list->prev->next = new_fd;
		*list->prev = new_fd;
	}
	return (new_fd);
}
