/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo <pendejoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:24:12 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/04 23:09:03 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 10000000

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

int     parse_init(char **argv);
int     check_map_size(char **map, int i);
int     check_extension(char *str);
char    **fill_map_tab(char **argv);
int     get_malloc_size(char **argv);
int     get_tab_size(char **tab);
int     get_collect(char **map);
int     map_is_closed(char **map, int i, int j);
int     map_params(char **map, int i, int j, int par_p);
int     map_is_valid(char **map, int i, int j);
int     map_way(char **map, int mx, int my);
int     get_player_pos_x(char **map, int i, int j);
int     get_player_pos_y(char **map, int px, int py);

// gnl src
char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strjoin(char **s1, char **s2);
char	*ft_strdup(char *s1);
void	read_n_stash(int fd, char **stash);
int		is_newline(char *stash);
char	*extract_line(char **stash, char **line);
char	*clean_stash(char *stash);
void	*free_data(char **stash, char **buf);

// utils
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

// err
void    err_msg(int i);
void    err_msg_2(int i);
#endif