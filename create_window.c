/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:28:21 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/01 15:38:05 by hyojeong         ###   ########.fr       */
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
	img_set.img[1] = mlx_xpm_file_to_image(mlx_info.mlx, "images/fish00.xpm", &img_set.width, &img_set.height);
	img_set.img[2] = mlx_xpm_file_to_image(mlx_info.mlx, "images/duck_front_00.xpm", &img_set.width, &img_set.height);
	img_set.img[3] = mlx_xpm_file_to_image(mlx_info.mlx, "images/tree_01.xpm", &img_set.width, &img_set.height);

	return (img_set);
}

void	make_window(t_map map, t_mlx mlx_info)
{
	t_img	img_set;
	int		i;
	int		j;

	img_set = make_img(mlx_info);
	i = 0;
	while (i < map.rows)
	{
		j = 0;
		while (j < map.columns)
		{
			if (map.map[i][j] == '1')
				mlx_put_image_to_window(mlx_info.mlx, mlx_info.win, img_set.img[0], j * 64, i * 64);
			else if (map.map[i][j] == 'C')
				mlx_put_image_to_window(mlx_info.mlx, mlx_info.win, img_set.img[1], j * 64, i * 64);
			else if (map.map[i][j] == 'E')
				mlx_put_image_to_window(mlx_info.mlx, mlx_info.win, img_set.img[3], j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx_info.mlx, mlx_info.win, img_set.img[2], map.player.x * 64, map.player.y * 64);
}
