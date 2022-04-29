#include "minilibx_opengl_20191021/mlx.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void *mlx;
	void *win;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	void *img6;
	void *img7;
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./images/tile.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./images/poketmon.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./images/chest.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./images/boats.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "./images/character.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 64, 0);
	mlx_put_image_to_window(mlx, win, img3, 128, 0);
	mlx_put_image_to_window(mlx, win, img4, 192, 64);
	mlx_put_image_to_window(mlx, win, img5, 0, 64);
	mlx_loop(mlx);
	return (0);
}