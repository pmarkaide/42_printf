/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_uns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:08:02 by pmarkaid          #+#    #+#             */
/*   Updated: 2023/11/16 11:10:30 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_uns(unsigned int n, int fd)
{
	int	p;

	p = 0;
	if (n >= 10)
	{
		p += ft_putnbr_fd_uns(n / 10, fd);
	}
	p += ft_putchar_fd(n % 10 + '0', fd);
	return (p);
}
