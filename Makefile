all:	
	gcc -L mlx -lmlx -framework OpenGL -framework AppKit ft_split.c create_window.c get_next_line.c get_next_line_utils.c main.c so_long.h map_parsing.c character_move.c so_long_utils.c
	./a.out maps/map1.ber

clean: 
	rm -rf *.out
