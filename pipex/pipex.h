/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:50:36 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/22 14:33:30 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <strings.h>
#include <string.h>

char	*ft_getenv(char *name, char **env);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isascii(int c);

#endif
