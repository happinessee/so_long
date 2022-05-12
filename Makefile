all:	
	gcc -L mlx -lmlx -framework OpenGL -framework AppKit srcs/ft_split.c srcs/create_window.c srcs/get_next_line.c srcs/get_next_line_utils.c srcs/main.c includes/so_long.h srcs/map_parsing.c srcs/character_move.c srcs/so_long_utils.c srcs/enemy_move.c
	./a.out maps/map1.ber

clean: 
	rm -rf *.out
