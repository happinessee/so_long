/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:58:11 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/02 17:34:27 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stddef.h>

typedef struct s_player
{
	int		x;
	int		y;
	int		collects;

	size_t	walks;
}	t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;

}	t_mlx;

typedef struct s_image
{
	void	*img[17];

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
	t_player	player;
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
int	moving(int key_num, t_map *map);
int	game_clear(t_map *map);

#endif
