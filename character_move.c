/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:20:39 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/01 16:06:07 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>

game_clear();

int	moving(int key_num, t_map map, t_mlx mlx_info)
{
	if (key_num == 53)	// esc
		exit(0);
	else if (key_num == 13)	// w
		move_w(&map, mlx_info);
	else if (key_num == 0)	// a
		move_a(&map, mlx_info);
	else if (key_num == 1)	// s
		move_s(&map, mlx_info);
	else if (key_num == 2)	// d
		move_d(&map, mlx_info);
	return (0);
}

/* 뒤로 도는 동작 넣어야 한다. */
void	move_w(t_map *map, t_mlx mlx_info)
{
	if (map->map[map->player.x][map->player.y + 1] != '1')
	{
		if (map->map[map->player.x][map->player.y + 1] == 'C')
		{
			map->map[map->player.x][map->player.y + 1] = '0';
			map->player.collects += 1;
		}
		if (map->map[map->player.x][map->player.y + 1] == 'E' && map->player.collects == map->collects)
		{
			game_clear();
		}
		map->map[map->player.x][map->player.y] = '0';
		map->map[map->player.x][map->player.y + 1] = 'P';
		map->player.y += 1;
	}
	else /* 뒤에서 아장아장 움직이는 모습만 넣어주자 */
	{
		;
	}
	make_window(*map, mlx_info);
}

void	move_a(t_map *map, t_mlx mlx_info)
{

}

void	move_s(t_map *map, t_mlx mlx_info)
{

}

void	move_d(t_map *map, t_mlx mlx_info)
{

}