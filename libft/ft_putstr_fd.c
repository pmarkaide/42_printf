/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:30:23 by pmarkaid          #+#    #+#             */
/*   Updated: 2023/11/17 13:05:12 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	p;

	p = 0;
	if (!s)
	{
		if (ft_putstr_fd("(null)", 1) < 0)
			return (-1);
		return (6);
	}
	while (*s)
	{
		if (write(fd, s, 1) < 0)
			return(-1);
		p++;
		s++;
	}
	return (p);
}
