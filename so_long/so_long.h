/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:24:12 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/01 11:42:11 by rvan-den         ###   ########.fr       */
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
int     check_map_size(char **map);
int     check_extension(char *str);
char    **fill_map_tab(int argc, char **argv);
int     get_malloc_size(int argc, char **argv);

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
    // while (1)
    // {
    //     map_to_parse = get_next_line(map_to_open);
    //     *map_tab = ft_strdup(map_to_parse);
    //     i++;
    //     if (map_to_parse == NULL)
    //         break;
    // }
#endif