#include "get_next_line.h"

void	copy_str(char *dst, const char *org, const size_t o_size)
{
	size_t	index;

	if (!org)
		return ;
	index = 0;
	while (org[index] && index + 1 < o_size)
	{
		dst[index] = org[index];
		index++;
	}
	dst[index] = '\0';
}

size_t	get_len(const char *str, const char sp_char)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
	{
		if (str[len] == sp_char)
			break ;
		len++;
	}
	return (len);
}
