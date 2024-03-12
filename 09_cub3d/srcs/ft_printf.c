/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:07:54 by juhyelee          #+#    #+#             */
/*   Updated: 2023/04/11 15:08:02 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		len;
	int		is_writen;

	va_start(arg, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			is_writen = put_arg(arg, *s);
		}
		else
			is_writen = put_char(*s);
		if (is_writen < 0)
		{
			va_end(arg);
			return (-1);
		}
		len += is_writen;
		s++;
	}
	va_end(arg);
	return (len);
}

int	put_arg(va_list arg, const char ch)
{
	if (ch == '%')
		return (put_char('%'));
	else if (ch == 'c')
		return (put_char(va_arg(arg, int)));
	else if (ch == 's')
		return (put_str(va_arg(arg, char *)));
	else if (ch == 'd' || ch == 'i')
		return (put_nbr(va_arg(arg, int)));
	else if (ch == 'u')
		return (put_nbr(va_arg(arg, unsigned int)));
	else if (ch == 'x')
		return (put_hex(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (ch == 'X')
		return (put_hex(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	else if (ch == 'p')
		return (put_addr(va_arg(arg, unsigned long)));
	return (0);
}
