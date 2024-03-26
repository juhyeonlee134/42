/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:33:52 by juhyelee          #+#    #+#             */
/*   Updated: 2024/03/26 13:15:42 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*get_next_line(int const fd)
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
	return (ret);
}

char	*__merge(char *dst, char const *org)
{
	char			*ret;
	size_t			dst_len;
	size_t const	org_len = ft_strlen(org);

	if (!dst)
	{
		ret = (char *)malloc(sizeof(char) * (org_len + 1));
		if (!ret)
			exit(EXIT_FAILURE);
		ft_strlcpy(ret, org, org_len + 1);
		return (ret);
	}
	dst_len = ft_strlen(dst);
	ret = (char *)malloc(sizeof(char) * (dst_len + org_len) + 1);
	if (!ret)
		exit(EXIT_FAILURE);
	ft_strlcpy(ret, dst, dst_len + 1);
	ft_strlcat(ret, org, dst_len + org_len + 1);
	free(dst);
	return (ret);
}

char	*__extract_string(char const *str, char const del)
{
	char	*ret;
	size_t	len_to_del;

	len_to_del = 0;
	while (str[len_to_del] != del)
		len_to_del++;
	if (len_to_del == 0)
		len_to_del = 1;
	ret = (char *)malloc(sizeof(char) * (len_to_del + 1));
	if (!ret)
		exit(EXIT_FAILURE);
	ft_strlcpy(ret, str, len_to_del + 1);
	return (ret);
}

void	__separate_string(char *str, char const del)
{
	size_t	len_to_del;
	size_t	index;

	len_to_del = 0;
	while (str[len_to_del] != del)
		len_to_del++;
	if (len_to_del == 0)
		len_to_del = 1;
	index = 0;
	while (str[len_to_del + index])
	{
		str[index] = str[len_to_del + index];
		index++;
	}
	str[index] = '\0';
}

int	__is_not_contain(char const *str, char const del)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str == del)
			return (0);
		str++;
	}
	return (1);
}
