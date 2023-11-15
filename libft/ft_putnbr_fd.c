/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:05:45 by pmarkaid          #+#    #+#             */
/*   Updated: 2023/11/15 15:39:06 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int p;

	p = 0;
	if (n == -2147483648)
		p += write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		p += ft_putchar_fd('-', fd);
		p += ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		p += ft_putnbr_fd(n / 10, fd);
		p += ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		p += ft_putchar_fd(n % 10 + '0', fd);
	return(p);
}
