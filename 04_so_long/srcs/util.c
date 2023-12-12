/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:35:21 by juhyelee          #+#    #+#             */
/*   Updated: 2023/04/06 13:27:20 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(const char ch)
{
	return (write(1, &ch, 1));
}

int	put_str(const char *s)
{
	int	len;

	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	len = 0;
	while (s[len])
	{
		len++;
	}
	return (write(1, s, len));
}

int	put_nbr(const long n)
{
	char	str[12];
	int		idx;
	long	num;

	num = (1 - 2 * (n < 0)) * n;
	if (num == 0)
	{
		return (put_char('0'));
	}
	str[11] = '\0';
	idx = 9;
	while (num != 0 && idx >= 0)
	{
		str[idx] = "0123456789"[num % 10];
		num /= 10;
		idx--;
	}
	if (n < 0)
	{
		str[idx] = '-';
		idx--;
	}
	return (put_str(str + idx + 1));
}

int	put_hex(unsigned long n, const char *const base)
{
	char	str[17];
	int		idx;

	if (n == 0)
	{
		return (put_char('0'));
	}
	str[16] = '\0';
	idx = 15;
	while (n != 0 && idx >= 0)
	{
		str[idx] = base[n % 16];
		n = n >> 4;
		idx--;
	}
	return (put_str(str + idx + 1));
}

int	put_addr(unsigned long n)
{
	char	str[17];
	int		idx;

	str[16] = '\0';
	idx = 15;
	if (n == 0)
	{
		str[idx] = '0';
		idx--;
	}
	while (n != 0 && idx >= 0)
	{
		str[idx] = "0123456789abcdef"[n % 16];
		n = n >> 4;
		idx--;
	}
	str[idx] = 'x';
	idx--;
	str[idx] = '0';
	idx--;
	return (put_str(str + idx + 1));
}
