NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L mlx -lmlx -framework OpenGL -framework Appkit

SRCS_DIR = ./srcs/
SRCS_BONUS_DIR = ./srcs_bonus/
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
		display_objs.c

SRC_BONUS = ft_split_bonus.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		ft_itoa_bonus.c \
		create_window_bonus.c \
		main_bonus.c \
		map_parsing_bonus.c \
		character_move_bonus.c \
		so_long_utils_bonus.c \
		enemy_move_bonus.c \
		display_objs_bonus.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC))
SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIR), $(SRC_BONUS))

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

INC =	so_long.h \
		so_long_bonus.h

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(MLX_FLAGS)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) -o $(NAME_BONUS) $(CFLAGS) $(OBJS_BONUS) $(MLX_FLAGS)

all : $(NAME)

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re :
	make fclean
	make all

bonus : $(NAME_BONUS)

.PHONY : all clean re bonus fclean
