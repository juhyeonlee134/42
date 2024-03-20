/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:33:52 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/20 13:57:46 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

char	*__get_string(int const fd)
{
	int			read_len;
	char		read_buffer[BUFFER_SIZE + 1];
	char		*ret;
	static char	*remain;

	while (__is_not_contain(remain, '\n'))
	{
		read_len = read(fd, read_buffer, BUFFER_SIZE);
		read_buffer[read_len] = '\0';
		if (read_len <= 0)
			break ;
		remain = __merge(remain, read_buffer);
	}
	if (!remain || remain[0] == '\0')
	{
		free(remain);
		remain = NULL;
		return (NULL);
	}
	ret = __extract_string(remain, '\n');
	__separate_string(remain, '\n');
	while (remain[0] == '\n')
		__separate_string(remain, '\n');
	return (ret);
}

int	__is_not_contain(char const *string, char const delimiter)
{
	if (!string)
		return (1);
	while (*string)
	{
		if (*string == delimiter)
			return (0);
		string++;
	}
	return (1);
}

char	*__merge(char *dest, char const *org)
{
	char			*ret;
	size_t			dest_len;
	size_t const	org_len = ft_strlen(org);

	if (!dest)
	{
		ret = (char *)malloc(sizeof(char) * (org_len + 1));
		if (!ret)
			exit(EXIT_FAILURE);
		ft_strlcpy(ret, org, org_len + 1);
		return (ret);
	}
	dest_len = ft_strlen(dest);
	ret = (char *)malloc(sizeof(char) * (dest_len + org_len) + 1);
	if (!ret)
		exit(1);
	ft_strlcpy(ret, dest, dest_len + 1);
	ft_strlcat(ret, org, dest_len + org_len + 1);
	return (ret);
}

char	*__extract_string(char const *string, char const delimiter)
{
	char	*ret;
	size_t	len_to_del;

	len_to_del = 0;
	while (string[len_to_del] != delimiter)
		len_to_del++;
	ret = (char *)malloc(sizeof(char) * (len_to_del + 1));
	if (!ret)
		exit(EXIT_FAILURE);
	ft_strlcpy(ret, string, len_to_del + 1);
	return (ret);
}

void	__separate_string(char *string, char const delimiter)
{
	size_t	len_to_del;
	size_t	index;

	len_to_del = 0;
	while (string[len_to_del] != delimiter)
		len_to_del++;
	index = 0;
	while (string[len_to_del + index + 1])
	{
		string[index] = string[len_to_del + index + 1];
		index++;
	}
	string[index] = '\0';
}
