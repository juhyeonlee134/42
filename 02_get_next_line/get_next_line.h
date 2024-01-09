#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_list
{
	int				fd;
	char			*remain;
	struct s_list	*prev;
	struct s_list	*next;
}t_list;

char	*get_next_line(int fd);
int		get_output(t_list *curr, char *ret);
int		read_buffer(t_list *curr, char *ret, char *buffer);

t_list	*find_fd(const t_list *list, const int fd);
t_list	*add_fd(t_list **list, const int fd);

char	*duplicate(const char *str, const char end);
void	push_to_front(char *str, const char sp);
void	merge(char *s1, char *s2);
size_t	get_len(const char *str);

#endif

