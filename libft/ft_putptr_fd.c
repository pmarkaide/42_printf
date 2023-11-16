/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:12:25 by pmarkaid          #+#    #+#             */
/*   Updated: 2023/11/16 13:08:11 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_putptr_fd(unsigned long ptr, int fd)
{    
	int p;

	p = 0;
	p += ft_putstr_fd("0x", fd);    // Print "0x" prefix
	p += ft_putnbr_fd_hex(ptr, 1 ,0);  // Print pointer address in hexadecimal
    return (p);
} 