NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L mlx -lmlx -framework OpenGL -framework Appkit

SRCS_DIR = ./srcs/
INCS_DIR = ./includes/

SRC = 	ft_split.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_itoa.c \
		create_window.c \
		main.c \
		map_parsing.c \
		character_move.c \
		so_long_utils.c \
		enemy_move.c \
		display_step.c \

SRCS = $(addprefix $(SRCS_DIR), $(SRC))

OBJS = $(SRCS: .c=.o)

INCS = $(INCS_DIR)so_long.h

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(MLX_FLAGS)

all : $(NAME)

clean :
	rm -f $(OBJS)

re : fclean all

fclean : clean
	rm -f $(NAME)

bonus : $(NAME)

.PHONY : all clean re bonus fclean
