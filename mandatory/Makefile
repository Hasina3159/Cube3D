NAME = cub3D

SRCS = ./srcs/ft_clean.c ./srcs/ft_image.c ./srcs/ft_init.c ./srcs/ft_key_handler.c ./srcs/ft_map_checker.c ./srcs/ft_move.c ./srcs/ft_parser.c ./srcs/ft_parser_1.c ./srcs/ft_renderer.c ./srcs/ft_renderer_part2.c ./srcs/ft_rotation.c ./srcs/ft_utils.c ./srcs/ft_utils_0.c ./srcs/main.c ./srcs/main_part2.c ./srcs/ft_file_checker.c

CC = gcc -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
	@cd libft/ && make; cd printf/ && make
	@cd minilibx-linux/ && make
	$(CC) $(OBJS) -o $(NAME) libft/libft.a libft/printf/libftprintf.a minilibx-linux/libmlx_Linux.a minilibx-linux/libmlx.a -lXext -lX11 -lm

all:	$(NAME)

clean:
	$(RM) $(OBJS)

cleanAll:
	@cd libft/ && make clean; cd printf/ && make clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

fcleanAll: fclean
	@cd libft/ && make fclean; cd printf/ && make fclean

re: fcleanAll all
.PHONY: all clean fclean re cleanAll fcleanAll