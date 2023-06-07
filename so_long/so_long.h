/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:24:12 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/07 13:00:27 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1000000

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
#include <stdbool.h>
#include "MLX42/include/MLX42/MLX42.h"
#define WIDTH 512
#define HEIGHT 

typedef	struct s_game
{
	mlx_t	*mlx;
	mlx_texture_t	*texture;
	mlx_image_t 	*player;
	mlx_image_t		*c_step;
	char	**map;	
	int	collect;
	int	steps;
	int	exit;
	int	p_y;
	int	p_x;
	int	m_y;
	int m_x;
}			t_game;

/*so_long_map*/
void	struct_init(t_game *init, char **argv);
void	aff_texture(t_game *af_map, int x, int y, char *path);
void	map_init(t_game *mp, char **map);
void	init_player(t_game *p, int i);
void	key(mlx_key_data_t keydata, void *param);
void	move_up(t_game *go);
void	move_down(t_game *go);
void	move_right(t_game *go);
void	move_left(t_game *go);


/* so_long_parse*/
void	mlx_test(int y, int x, char *path);
int     parse_init(char **argv);
int     check_map_size(char **map, int i);
int     check_extension(char *str);
char    **fill_map_tab(char **argv);
int     get_malloc_size(char **argv);
int     gmsy(char **tab);
int 	gmsx(char **tab);
int     get_collect(char **map);
int     map_is_closed(char **map, int i, int j);
int     map_params(char **map, int i, int j, int par_p);
int     map_is_valid(char **map, int i, int j);
int     map_way(char **map, int mx, int my);
int		map_way_ok(char **map, int px, int py);
int     gpx(char **map, int i, int j);
int     gpy(char **map, int px, int py);
int		parse_check(char **argv);

/* gnl src */
char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strjoin(char **s1, char **s2);
char	*ft_strdup(char *s1);
void	read_n_stash(int fd, char **stash);
int		is_newline(char *stash);
char	*extract_line(char **stash, char **line);
char	*clean_stash(char *stash);
void	*free_data(char **stash, char **buf);

/* utils */

int     ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char    **ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
int     ft_isascii(int c);
void    ft_putsterr(char *str);
void	free_tabs(char **tab);
char	**clone_map(char **map);
char	*ft_itoa(int n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

/* err */

void    err_msg(int i);
void    err_msg_2(int i);
#endif