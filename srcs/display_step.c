/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:28:24 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/13 14:38:56 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

#include <stdlib.h>

void	draw_step_count(t_map map)
{
	char	*str;

	str = ft_itoa(map.player.walks);
	mlx_put_image_to_window(map.mlx_info.mlx, map.mlx_info.win, \
						map.img_set.img[14], 0, 0);
	mlx_string_put(map.mlx_info.mlx, map.mlx_info.win, 24, 36, 0xFF0000, str);
	free(str);
}