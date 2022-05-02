/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:28:21 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/02 14:41:27 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

#include <stdio.h>

t_mlx	make_mlx(t_map map)
{
	t_mlx	mlx_info;

	ft_memset(&mlx_info, 0, sizeof(t_mlx));
	mlx_info.mlx = mlx_init();
	mlx_info.win = mlx_new_window(mlx_info.mlx, map.columns * 64, map.rows * 64, "obbang's_travel!");
	return (mlx_info);
}

t_img	make_img(t_mlx mlx_info)
{
	t_img	img_set;

	ft_memset(&img_set, 0, sizeof(t_img));
	img_set.img[0] = mlx_xpm_file_to_image(mlx_info.mlx, "images/tree_00.xpm", &img_set.width, &img_set.height);
	img_set.img[1] = mlx_xpm_file_to_image(mlx_info.mlx, "images/tree_01.xpm", &img_set.width, &img_set.height);
	img_set.img[2] = mlx_xpm_file_to_image(mlx_info.mlx, "images/duck_front_00.xpm", &img_set.width, &img_set.height);
	img_set.img[3] = mlx_xpm_file_to_image(mlx_info.mlx, "images/duck_front_01.xpm", &img_set.width, &img_set.height);
	img_set.img[4] = mlx_xpm_file_to_image(mlx_info.mlx, "images/duck_front_02.xpm", &img_set.width, &img_set.height);
	img_set.img[5] = mlx_xpm_file_to_image(mlx_info.mlx, "images/duck_back_00.xpm", &img_set.width, &img_set.height);
	img_set.img[6] = mlx_xpm_file_to_image(mlx_info.mlx, "images/duck_back_01.xpm", &img_set.width, &img_set.height);
	img_set.img[7] = mlx_xpm_file_to_image(mlx_info.mlx, "images/duck_back_02.xpm", &img_set.width, &img_set.height);
	img_set.img[8] = mlx_xpm_file_to_image(mlx_info.mlx, "images/duck_left_00.xpm", &img_set.width, &img_set.height);
	img_set.img[9] = mlx_xpm_file_to_image(mlx_info.mlx, "images/duck_left_01.xpm", &img_set.width, &img_set.height);
	img_set.img[10] = mlx_xpm_file_to_image(mlx_info.mlx, "images/duck_right_00.xpm", &img_set.width, &img_set.height);
	img_set.img[11] = mlx_xpm_file_to_image(mlx_info.mlx, "images/duck_right_01.xpm", &img_set.width, &img_set.height);
	img_set.img[12] = mlx_xpm_file_to_image(mlx_info.mlx, "images/fish00.xpm", &img_set.width, &img_set.height);
	img_set.img[13] = mlx_xpm_file_to_image(mlx_info.mlx, "images/fish01.xpm", &img_set.width, &img_set.height);
	img_set.img[14] = mlx_xpm_file_to_image(mlx_info.mlx, "images/tile.xpm", &img_set.width, &img_set.height);
	img_set.img[15] = mlx_xpm_file_to_image(mlx_info.mlx, "images/duck2_00.xpm", &img_set.width, &img_set.height);
	img_set.img[16] = mlx_xpm_file_to_image(mlx_info.mlx, "images/cat_00.xpm", &img_set.width, &img_set.height);
	return (img_set);
}

void	make_window(t_map map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map.rows)
	{
		j = 0;
		while (j < map.columns)
		{
			mlx_put_image_to_window(map.mlx_info.mlx, map.mlx_info.win, map.img_set.img[14], j * 64, i * 64);
			if (map.map[i][j] == '1')
				mlx_put_image_to_window(map.mlx_info.mlx, map.mlx_info.win, map.img_set.img[0], j * 64, i * 64);
			else if (map.map[i][j] == 'C')
				mlx_put_image_to_window(map.mlx_info.mlx, map.mlx_info.win, map.img_set.img[12], j * 64, i * 64);
			else if (map.map[i][j] == 'E')
				mlx_put_image_to_window(map.mlx_info.mlx, map.mlx_info.win, map.img_set.img[15], j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(map.mlx_info.mlx, map.mlx_info.win, map.img_set.img[2], map.player.x * 64, map.player.y * 64);
}
