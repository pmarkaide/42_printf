/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:28:41 by pmarkaid          #+#    #+#             */
/*   Updated: 2023/11/17 13:14:46 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_hex(unsigned long n, int fd, int uppercase)
{
	int	p;
	int e;

	p = 0;
	e = 0;
	if (n >= 16)
	{
		p += ft_putnbr_fd_hex(n / 16, fd, uppercase);
		p += ft_putnbr_fd_hex(n % 16, fd, uppercase);
	}
	else
	{
		if (n < 10)
			p += ft_putchar_fd(n + '0', fd);
		else
		{
			if (uppercase)
				p += ft_putchar_fd(n - 10 + 'A', fd);
			else
				p += ft_putchar_fd(n - 10 + 'a', fd);
		}
	}
	if(p < e)
		return (-1);
	return (p);
}
