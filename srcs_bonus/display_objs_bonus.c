/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_objs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:28:24 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/14 14:36:48 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../mlx/mlx.h"

#include <stdlib.h>

void	draw_step_count(t_map map)
{
	char	*str;

	str = ft_itoa(map.player.walks);
	mlx_put_image_to_window(map.mlx_info.mlx, map.mlx_info.win, \
						map.img_set.img[17], 24, 24);
	mlx_string_put(map.mlx_info.mlx, map.mlx_info.win, 24, 36, 0xFF0000, str);
	free(str);
}

void	draw_tree(t_map map, int i, int j)
{
	if (map.frame < 30)
		mlx_put_image_to_window(map.mlx_info.mlx, map.mlx_info.win, \
			map.img_set.img[0], j * 64, i * 64);
	else
		mlx_put_image_to_window(map.mlx_info.mlx, map.mlx_info.win, \
			map.img_set.img[1], j * 64, i * 64);
}

void	draw_fish(t_map map, int i, int j)
{
	if (map.frame < 30)
		mlx_put_image_to_window(map.mlx_info.mlx, map.mlx_info.win, \
			map.img_set.img[12], j * 64, i * 64);
	else
		mlx_put_image_to_window(map.mlx_info.mlx, map.mlx_info.win, \
			map.img_set.img[13], j * 64, i * 64);
}

void	draw_player(t_map map)
{
	mlx_put_image_to_window(map.mlx_info.mlx, map.mlx_info.win, \
	map.player.p_img, map.player.x * 64, map.player.y * 64);
}

void	draw_enemy(t_map map)
{
	mlx_put_image_to_window(map.mlx_info.mlx, map.mlx_info.win, \
	map.img_set.img[16], map.enemy.x * 64, map.enemy.y * 64);
}
