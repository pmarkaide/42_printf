/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:22:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2023/11/16 13:08:33 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

int	ft_putformat(char specifier, va_list args)
{
	int	p;

	p = 0;
	if (specifier == '%')
		p += ft_putchar_fd('%', 1);
	else if (specifier == 'c')
		p += ft_putchar_fd(va_arg(args, int), 1);
	else if (specifier == 's')
		p += ft_putstr_fd(va_arg(args, char *), 1);
	else if (specifier == 'd' || specifier == 'i')
		p += ft_putnbr_fd(va_arg(args, int), 1);
	else if (specifier == 'u')
		p += ft_putnbr_fd_uns(va_arg(args, unsigned long), 1);	
	else if (specifier == 'x')
		p += ft_putnbr_fd_hex(va_arg(args, unsigned long), 1, 0);
	else if (specifier == 'X')
		p += ft_putnbr_fd_hex(va_arg(args, unsigned long), 1, 1);
	else if(specifier == 'p')
		p += ft_putptr_fd(va_arg(args, unsigned long), 1);
	return (p);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		p;

	va_start(args, format);
	p = 0;
	while (*format)
	{
		if (*format == '%')
			p += ft_putformat(*(++format), args);
		else
			p += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (p);
}
