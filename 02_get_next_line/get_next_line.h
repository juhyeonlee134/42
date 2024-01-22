#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
void	copy_str(char *dst, const char *org, const size_t o_size);
size_t	get_len(const char *str, const char sp_char);

#endif
