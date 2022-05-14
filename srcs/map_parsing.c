/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:32:16 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/14 18:06:23 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void	set_collects_enemy(t_map *map, int j, int i)
{
	if (map->collects == 0)
	{
		map->enemy.x = j;
		map->enemy.y = i;
	}
	map->collects += 1;
}

static void	map_checker(char **str, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->columns)
		{
			if (str[0][j] != '1' || str[i][0] != '1' \
				|| str[i][ft_strlen(str[i]) - 1] != '1')
				print_err("Error : The map must be blocked by a wall.");
			if (str[i][j] == 'P')
			{
				map->exist_player += 1;
				map->player.x = j;
				map->player.y = i;
			}
			else if (str[i][j] == 'C')
				set_collects_enemy(map, j, i);
			else if (str[i][j] == 'E')
				map->escape += 1;
		}
	}
}

char	**load_map(t_map *map, char *argv)
{
	int		fd;
	char	*before_map;
	char	**maps;
	char	*tmp;

	fd = open(argv, O_RDONLY);
	before_map = get_next_line(fd);
	map->columns = ft_strlen(before_map) - 1;
	map->rows = 1;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		before_map = ft_strjoin(before_map, tmp, 1);
		map->rows += 1;
	}
	if (map->rows * map->columns != (int)(ft_strlen(before_map) - map->rows + 1))
	{
		printf("%d %d %zu\n", map->rows, map->columns, ft_strlen(before_map));
		print_err("Error : Maps must be rectangular.");
	}
	maps = ft_split(before_map, '\n');
	free(before_map);
	return (maps);
}

t_map	make_map(char *argv)
{
	char	**maps;
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	maps = load_map(&map, argv);
	map_checker(maps, &map);
	if (map.exist_player != 1)
		print_err("Error : 1 player must exist.");
	if (map.collects < 1)
		print_err("Error : 1 collect must exist");
	map.map = maps;
	return (map);
}
