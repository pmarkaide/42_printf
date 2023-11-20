/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:30:23 by pmarkaid          #+#    #+#             */
/*   Updated: 2023/11/20 12:11:51 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	p;

	p = 0;
	if (!s)
	{
		p = ft_error_w(p, ft_putstr_fd("(null)", 1));
		if (p == -1)
			return (-1);
		return (6);
	}
	while (*s)
	{
		p = ft_error_w(p, write(fd, s, 1));
		if (p == -1)
			return (-1);
		s++;
	}
	return (p);
}
