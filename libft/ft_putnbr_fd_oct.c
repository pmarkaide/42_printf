/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_oct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:31:25 by pmarkaid          #+#    #+#             */
/*   Updated: 2023/11/16 10:59:17 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_oct(unsigned int n, int fd)
{
	int	p;

	p = 0;
	if (n >= 8)
	{
		p += ft_putnbr_fd_oct(n / 8, fd);
		p += ft_putchar_fd(n % 8 + '0', fd);
	}
	else
	{
		p += ft_putchar_fd(n + '0', fd);
	}
	return (p);
}
