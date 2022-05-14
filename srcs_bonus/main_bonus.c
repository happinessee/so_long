/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:58:14 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/14 17:05:40 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "../mlx/mlx.h"
#include "../includes/so_long_bonus.h"

void	frame(t_map *map)
{
	map->frame++;
	if (map->frame >= 60)
		map->frame = 0;
}

int	loop(t_map *map)
{
	make_window(*map);
	frame(map);
	if (map->frame == 0)
	{
		enemy_move(map);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		print_err("Error : There must be only one parameter.");
	if (argv[1][ft_strlen(argv[1]) - 1] != 'r' || \
		argv[1][ft_strlen(argv[1]) - 2] != 'e' || \
		argv[1][ft_strlen(argv[1]) - 3] != 'b' || \
		argv[1][ft_strlen(argv[1]) - 4] != '.')
		print_err("Error : The map extension must be .ber");
	map = make_map(argv[1]);
	map.mlx_info = make_mlx(map);
	map.img_set = make_img(map.mlx_info);
	map.player.p_img = map.img_set.img[2];
	map.enemy.p_img = map.img_set.img[16];
	make_window(map);
	mlx_hook(map.mlx_info.win, 2, 0, &moving, &map);
	mlx_hook(map.mlx_info.win, 17, 0, &game_clear, &map);
	mlx_loop_hook(map.mlx_info.mlx, &loop, &map);
	mlx_loop(map.mlx_info.mlx);
	return (0);
}
