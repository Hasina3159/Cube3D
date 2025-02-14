# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhajanol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 12:33:59 by fhajanol          #+#    #+#              #
#    Updated: 2024/02/26 08:40:30 by fhajanol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c \
		ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_split.c \
		ft_strchr.c ft_strdup.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_substr.c ft_tolower.c \
		ft_toupper.c ft_strmapi.c ft_striteri.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		ft_putnbr_fd.c

BONUS_SRCS	= ft_lstadd_back.c ft_lstclear.c ft_lstiter.c\
			 ft_lstmap.c ft_lstsize.c ft_lstadd_front.c\
			ft_lstdelone.c ft_lstlast.c ft_lstnew.c

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

OBJS	= $(SRCS:.c=.o)

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

.c.o	:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)	: $(OBJS)
		ar rcs $(NAME) $(OBJS)

bonus	: $(BONUS_OBJS) $(OBJS)
		ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
		
all : $(NAME)

clean :
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean	: clean
		$(RM) $(NAME)

re : fclean all
