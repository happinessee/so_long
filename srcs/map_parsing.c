/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:32:16 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/02 18:04:46 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void	print_err(char *str)
{
	printf("%s\n", str);
	exit(0);
}

static void	map_checker(char **str, t_map *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->rows)
	{
		j = -1;
		while (++j < info->columns)
		{
			if (str[0][j] != '1' || str[i][0] != '1' \
				|| str[i][ft_strlen(str[i]) - 1] != '1')
				print_err("Error : The map must be blocked by a wall.");
			if (str[i][j] == 'P')
			{
				info->exist_player += 1;
				ft_memset(&info->player, 0, sizeof(t_player));
				info->player.x = j;
				info->player.y = i;
			}
			else if (str[i][j] == 'C')
				info->collects += 1;
			else if (str[i][j] == 'E')
				info->escape += 1;
		}
	}
}

char	**load_map(t_map *info, char *argv)
{
	int		fd;
	char	*map;
	char	**maps;
	char	*tmp;

	fd = open(argv, O_RDONLY);
	map = get_next_line(fd);
	info->columns = ft_strlen(map) - 1;
	info->rows = 1;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		map = ft_strjoin(map, tmp, 2);
		info->rows += 1;
	}
	if (info->rows * info->columns != (ft_strlen(map) - info->rows + 1))
		print_err("Error : Maps must be rectangular.");
	maps = ft_split(map, '\n');
	return (maps);
}

t_map	make_map(char *argv)
{
	char	*tmp;
	char	**maps;
	t_map	info;

	ft_memset(&info, 0, sizeof(t_map));
	maps = load_map(&info, argv);
	map_checker(maps, &info);
	if (info.exist_player != 1)
		print_err("Error : 1 player must exist.");
	if (info.collects < 1)
		print_err("Error : 1 collect must exist");
	info.map = maps;
	return (info);
}
