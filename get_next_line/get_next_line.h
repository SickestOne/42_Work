/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:16:22 by rvan-den          #+#    #+#             */
/*   Updated: 2023/02/22 15:20:33 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif 

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
#include <fcntl.h>

char *get_next_line(int fd);
size_t ft_strlen(const char *s);
char *ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);

#endif
