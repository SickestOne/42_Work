/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:24:12 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/02 12:06:27 by rvan-den         ###   ########.fr       */
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


int     parse_init(int argc, char **argv);
int     check_map_size(int argc, char **argv, char **map, int i);
int     check_extension(char *str);
char    **fill_map_tab(int argc, char **argv);
int     get_malloc_size(int argc, char **argv);
int     get_tab_size(char **tab);
int     map_is_closed(char **map, int i, int j);
int     map_params(char **map, int i, int j, int par_p);
int     map_is_valid(char **map, int i, int j);
int     can_do_map(char **map, int i, int j);

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
char    **ft_split(char const *s, char c);
int     ft_isascii(int c);
void    ft_putsterr(char *str);
void	free_tabs(char **tab);

// err
void    err_msg(int i);
void    err_msg_2(int i);
#endif