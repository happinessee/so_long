/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:58:14 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/01 16:01:13 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>

#include "mlx/mlx.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	mlx_info;

	if (argc != 2)
	{
		print_err("Error : There must be only one parameter.");
	}
	if (argv[1][ft_strlen(argv[1]) - 1] != 'r' ||\
		argv[1][ft_strlen(argv[1]) - 2] != 'e' ||\
		argv[1][ft_strlen(argv[1]) - 3] != 'b' ||\
		argv[1][ft_strlen(argv[1]) - 4] != '.')
	{
		print_err("Error : The map extension must be .ber");
	}
	map = make_map(argv[1]);
	mlx_info = make_mlx(map);
	make_window(map, mlx_info);
	mlx_hook(mlx_info.win, 2, 0, &moving, 0);
	mlx_loop(mlx_info.mlx);
	return (0);
}
