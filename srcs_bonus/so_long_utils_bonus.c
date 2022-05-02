/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:48:20 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/02 17:32:39 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

#include <stddef.h>
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

int	game_clear(t_map *map)
{	
	mlx_destroy_window(map->mlx_info.mlx, map->mlx_info.win);
	exit(0);
}
