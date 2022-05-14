/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:48:20 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/14 13:59:59 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*memory;

	i = 0;
	memory = (unsigned char *)b;
	while (i < len)
	{
		memory[i] = c;
		i++;
	}
	return (memory);
}

void	print_err(char *str)
{
	printf("%s\n", str);
	exit(0);
}

int	game_clear(t_map *map)
{	
	printf("Game Clear!!!\n");
	mlx_destroy_window(map->mlx_info.mlx, map->mlx_info.win);
	exit(0);
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
