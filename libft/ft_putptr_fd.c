/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:12:25 by pmarkaid          #+#    #+#             */
/*   Updated: 2023/11/17 13:11:44 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_fd(unsigned long ptr, int fd)
{
	int	p;
	int e;

	p = 0;
	e = 0;
	p += ft_putstr_fd("0x", fd);
	if (p < e)
		return (-1);
	e = p;
	p += ft_putnbr_fd_hex(ptr, fd, 0);
	if (p < e)
		return (-1);
	return (p);
}
