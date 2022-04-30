/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:58:14 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/30 16:36:38 by hyojeong         ###   ########.fr       */
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
	t_map map;

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
	printf("map OK\n");
	make_window(map);
	return (0);
}
