/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:08:03 by juhyelee          #+#    #+#             */
/*   Updated: 2023/04/06 13:27:25 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	put_arg(va_list arg, const char ch);
int	put_char(const char ch);
int	put_str(const char *s);
int	put_nbr(const long n);
int	put_hex(unsigned long n, const char *const base);
int	put_addr(unsigned long n);

#endif
