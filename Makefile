all:
	make -C mandatory
	mv -f mandatory/cub3D .

clean:
	make -C mandatory cleanAll
	make -C bonus cleanAll

fclean:
	make -C mandatory fcleanAll
	make -C bonus fcleanAll
	rm -f cub3D

re: fclean all

bonus:
	make -C bonus
	mv -f bonus/cub3D .

reBonus: fclean bonus

.PHONY: all clean fclean re bonus reBonus
