/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:22:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2023/11/15 16:10:22 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_putformat(char specifier, va_list args)
{
	int	p;

	p = 0;
	if (specifier == 'c')
		p += ft_putchar_fd(va_arg(args, int), 1);
	else if (specifier == 's')
		p += ft_putstr_fd(va_arg(args, char *), 1);
	else if (specifier == 'd')
		p += ft_putnbr_fd(va_arg(args, int), 1);
	//else if(specifier == 'p')
	//else if(specifier == 'i')
	//else if(specifier == 'u')
	//else if(specifier == 'x')
	//else if(specifier == 'X')
	//else if(specifier == '%')
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

int	main(void)
{
	char ch = 'A';
	char *str = "Hello, World!";
	int decimalNum = 42;
	unsigned int unsignedNum = 100;
	int hexNum = 0xABCD;

	printf("%%c: %c\n", ch);
	printf("%%s: %s\n", str);
	printf("%%p: %p\n", (void *)&hexNum);
	printf("%%d: %d\n", decimalNum);
	printf("%%i: %i\n", decimalNum);
	printf("%%u: %u\n", unsignedNum);
	printf("%%x: %x\n", hexNum);
	printf("%%X: %X\n", hexNum);
	printf("%%%%: %%\n");

	int p1 = printf("char: %d\n", decimalNum);
	printf("%d\n", p1);
	int p2 = ft_printf("char: %d\n", decimalNum);
	printf("%d\n", p2);

	return (0);
}