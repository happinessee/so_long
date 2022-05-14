/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:43:51 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/14 18:37:50 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../mlx/mlx.h"

static void	enemy_d(t_map *map, int *flag, int *cnt)
{
	if (*flag == 0)
	{
		if (!(map->map[map->enemy.y][map->enemy.x + 1] == '1'))
			map->enemy.x += 1;
		*cnt += 1;
	}
}

static void	enemy_w(t_map *map, int *flag, int *cnt)
{
	if (*flag == 1)
	{
		if (!(map->map[map->enemy.y + 1][map->enemy.x] == '1'))
			map->enemy.y += 1;
		*cnt += 1;
	}
}

static void	enemy_a(t_map *map, int *flag, int *cnt)
{
	if (*flag == 2)
	{
		if (!(map->map[map->enemy.y][map->enemy.x - 1] == '1'))
			map->enemy.x -= 1;
		*cnt += 1;
	}
}

static void	enemy_s(t_map *map, int *flag, int *cnt)
{
	if (*flag == 3)
	{
		if (!(map->map[map->enemy.y - 1][map->enemy.x] == '1'))
			map->enemy.y -= 1;
		*cnt += 1;
	}
}

void	enemy_move(t_map *map)
{
	static int	flag;
	static int	cnt;

	enemy_d(map, &flag, &cnt);
	enemy_w(map, &flag, &cnt);
	enemy_a(map, &flag, &cnt);
	enemy_s(map, &flag, &cnt);
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
