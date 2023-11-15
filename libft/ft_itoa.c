/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:51:48 by pmarkaid          #+#    #+#             */
/*   Updated: 2023/11/09 10:50:19 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int nb)
{
	long	n;
	int		len;

	len = 0;
	n = (long)nb;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		digits;
	long	nb;

	nb = (long)n;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	digits = ft_numlen(nb);
	res = (char *)malloc(sizeof(char) * (digits + 1));
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	res[digits--] = '\0';
	res[digits--] = (nb % 10) + '0';
	while (nb >= 10)
	{
		nb = nb / 10;
		res[digits--] = (nb % 10) + '0';
	}
	return (res);
}
