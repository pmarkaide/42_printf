# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 11:21:07 by pmarkaid          #+#    #+#              #
#    Updated: 2023/11/21 11:39:06 by pmarkaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRCS = \
	ft_printf.c \
	ft_putchar_fd.c \
	ft_putnbr_fd.c \
	ft_putnbr_fd_hex.c \
	ft_putnbr_fd_uns.c \
	ft_putptr_fd.c \
	ft_putstr_fd.c
       
OBJS = $(SRCS:.c=.o)

INCLUDES = -I .

CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
