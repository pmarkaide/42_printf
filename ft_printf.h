/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:03:37 by pmarkaid          #+#    #+#             */
/*   Updated: 2023/11/20 13:22:16 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putformat(char specifier, va_list args);
int	ft_error_w(int print_count, int write_return);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putnbr_fd_uns(unsigned int n, int fd);
int	ft_putnbr_fd_hex(unsigned long n, int fd, int uppercase);
int	ft_putptr_fd(unsigned long ptr, int fd);

#endif