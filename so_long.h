/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:58:11 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/30 16:32:13 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>

typedef struct s_map
{
	char	**map;
	int 	rows;
	int 	columns;
	
	int 	player;
	int 	collects;
	int		escape;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;

}	t_mlx;

typedef struct s_image
{
	void	*img[15];

	int		height;
	int		width;
}	t_img;

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
void	make_window(t_map map);

#endif
