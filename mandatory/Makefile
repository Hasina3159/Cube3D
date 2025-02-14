NAME = cube3d

SRCS = $(shell find . -name "*.c" | grep "srcs/" | tr '\n' ' ')

CC = cc

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
	@cd libft/ && make; cd printf/ && make
	@cd minilibx-linux/ && make
	$(CC) $(OBJS) -o $(NAME) libft/libft.a libft/printf/libftprintf.a minilibx-linux/libmlx_Linux.a minilibx-linux/libmlx.a -lXext -lX11 -lm -g

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