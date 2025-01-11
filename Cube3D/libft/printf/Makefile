# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhajanol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 09:24:07 by fhajanol          #+#    #+#              #
#    Updated: 2024/03/04 11:42:43 by fhajanol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_putaddr.c ft_printf.c ft_putchar.c \
		ft_putstr.c ft_strlen.c ft_putnbr_base.c \
		ft_putnbr.c ft_strncmp.c

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

OBJS	= $(SRCS:.c=.o)

.c.o	:
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
		ar rc $(NAME) $(OBJS)

all	: $(NAME)

clean :
		$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME)

re : fclean all
