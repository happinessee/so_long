/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:58:11 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/13 14:55:40 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>

typedef struct s_player
{
	int		x;
	int		y;
	int		collects;
	void	*p_img;

	size_t	walks;
}	t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;

}	t_mlx;

typedef struct s_image
{
	void	*img[18];

	int		height;
	int		width;
}	t_img;

typedef struct s_map
{
	char		**map;
	int 		rows;
	int 		columns;
	int 		collects;
	int			escape;
	int			exist_player;
	int			frame;
	t_player	player;
	t_player	enemy;
	t_mlx		mlx_info;
	t_img		img_set;
}	t_map;


// gnl
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2, int flag);

// split
char	**ft_split(char const *str, char c);

// map_parsing
void	print_err(char *str);
void	*ft_memset(void *b, int c, size_t len);
t_map	make_map(char *argv);

// create_window
t_mlx	make_mlx(t_map map);
t_img	make_img(t_mlx mlx_info);
void	make_window(t_map map);

// character_move
int		moving(int key_num, t_map *map);
int		game_clear(t_map *map);

// enemy_move
void	enemy_move(t_map *map);
void	check_enemy(t_map map);

// itoa
char	*ft_itoa(int n);

// step_count
void	draw_step_count(t_map map);
#endif
