/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:28:41 by pmarkaid          #+#    #+#             */
/*   Updated: 2023/11/16 10:59:07 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_hex(unsigned int n, int fd, int uppercase)
{
	int	p;

	p = 0;
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
	return (p);
}
