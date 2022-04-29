#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include "mlx/mlx.h"
#include "get_next_line.h"

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_EXIT		17 //Exit program key code

#define KEY_ESC			53

# define TILE_SIZE 64
# define ROWS 11
# define COLS 15
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE

# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))


int		main(void)
{
	int map[11][15] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	int		i;
	int		j;
	void *img3;
	void *mlx;
	void *win;
	int	img_width;
	int img_height;
	int	fd = open("maps/map1.ber", O_RDONLY);

	i = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, TILE_SIZE * 15, TILE_SIZE * 11, "obbang's_travel");
	img3 = mlx_xpm_file_to_image(mlx, "images/tree_00.xpm", &img_width, &img_height);

	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if (map[i][j] == 1)
			{
				mlx_put_image_to_window(mlx, win, img3, j * TILE_SIZE, i * TILE_SIZE);
			}
			j++;
		}
		i++;
	}

	mlx_loop(mlx);
}
