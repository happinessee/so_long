/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:20:39 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/02 14:00:43 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>
#include <stdio.h>

void	game_clear()
{
	exit(0);
}

/* 뒤로 도는 동작 넣어야 한다. */
void	move_w(t_map *map)
{
	if (map->map[map->player.y - 1][map->player.x] != '1')
	{
		if (map->map[map->player.y - 1][map->player.x] == 'C')
		{
			map->map[map->player.y - 1][map->player.x] = '0';
			map->player.collects += 1;
		}
		if (map->map[map->player.y - 1][map->player.x] == 'E' && map->player.collects == map->collects)
		{
			game_clear();
		}
		map->map[map->player.y][map->player.x] = '0';
		map->player.y -= 1;
		map->player.walks += 1;
	}
	else // 뒤에서 아장아장 움직이는 모습만 넣어주자 
	{
		;
	}
	make_window(*map);
}

void	move_a(t_map *map)
{
	if (map->map[map->player.y][map->player.x - 1] != '1')
	{
		if (map->map[map->player.y][map->player.x - 1] == 'C')
		{
			map->map[map->player.y][map->player.x - 1] = '0';
			map->player.collects += 1;
		}
		if (map->map[map->player.y][map->player.x - 1] == 'E' && map->player.collects == map->collects)
		{
			game_clear();
		}
		map->map[map->player.y][map->player.x] = '0';
		map->player.x -= 1;
		map->player.walks += 1;
	}
	else // 뒤에서 아장아장 움직이는 모습만 넣어주자 
	{
		;
	}
	make_window(*map);
}

void	move_s(t_map *map)
{
	if (map->map[map->player.y + 1][map->player.x] != '1')
	{
		if (map->map[map->player.y + 1][map->player.x] == 'C')
		{
			map->map[map->player.y + 1][map->player.x] = '0';
			map->player.collects += 1;
		}
		if (map->map[map->player.y + 1][map->player.x] == 'E' && map->player.collects == map->collects)
		{
			game_clear();
		}
		map->map[map->player.y][map->player.x] = '0';
		map->player.y += 1;
		map->player.walks += 1;
	}
	else // 뒤에서 아장아장 움직이는 모습만 넣어주자 
	{
		;
	}
	make_window(*map);
}

void	move_d(t_map *map)
{
	if (map->map[map->player.y][map->player.x + 1] != '1')
	{
		if (map->map[map->player.y][map->player.x + 1] == 'C')
		{
			map->map[map->player.y][map->player.x + 1] = '0';
			map->player.collects += 1;
		}
		if (map->map[map->player.y][map->player.x + 1] == 'E' && map->player.collects == map->collects)
		{
			game_clear();
		}
		map->map[map->player.y][map->player.x] = '0';
		map->player.x += 1;
		map->player.walks += 1;
	}
	else // 뒤에서 아장아장 움직이는 모습만 넣어주자 
	{
		;
	}
	make_window(*map);
}

int	moving(int key_num, t_map *map)
{
	if (key_num == 53)	// esc
		exit(0);
	else if (key_num == 13)	// w
		move_w(map);
	else if (key_num == 0)	// a
		move_a(map);
	else if (key_num == 1)	// s
		move_s(map);
	else if (key_num == 2)	// d
		move_d(map);
	printf("walks : %zu\n", map->player.walks);
	return (0);
}
