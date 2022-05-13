/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:43:51 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/13 11:38:50 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

#include <stdio.h>
#include <stdlib.h>

void	enemy_move(t_map *map)
{
	static int	flag;
	static int	cnt;

	if (flag == 0)
	{
		if (!(map->map[map->enemy.y][map->enemy.x + 1] == '1'))
			map->enemy.x += 1;
		cnt += 1;
	}
	else if (flag == 1)
	{
		if (!(map->map[map->enemy.y + 1][map->enemy.x] == '1'))
			map->enemy.y += 1;
		cnt += 1;
	}
	else if (flag == 2)
	{
		if (!(map->map[map->enemy.y][map->enemy.x - 1] == '1'))
			map->enemy.x -= 1;
		cnt += 1;
	}
	else
	{
		if (!(map->map[map->enemy.y - 1][map->enemy.x] == '1'))
			map->enemy.y -= 1;
		cnt += 1;
	}
	if (cnt == 4)
	{
		cnt = 0;
		flag += 1;
	}
	if (flag > 3)
		flag = 0;
	mlx_put_image_to_window(map->mlx_info.mlx, map->mlx_info.win, \
				map->img_set.img[16], map->enemy.x * 64, map->enemy.y * 64);
}

void	check_enemy(t_map map)
{
	if (map.enemy.y == map.player.y && map.enemy.x == map.player.x)
	{
		printf("Game Over...\n");
		mlx_destroy_window(map.mlx_info.mlx, map.mlx_info.win);
		exit(0);
	}
}