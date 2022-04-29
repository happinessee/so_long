all:	
	gcc -L mlx -lmlx -framework OpenGL -framework AppKit main.c -o main.out
	./main.out

clean: 
	rm -rf *.out
