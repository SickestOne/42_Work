/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:50:36 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/29 10:51:21 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <strings.h>
# include <string.h>

char	*ft_getenv(char *name, char **env);
char	*ft_execpath(char *exec_cmd_av, char **env);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isascii(int c);
void	exec_cmd(char *cmd, char **env);
void	free_tabs(char **tab);
void	ft_putstr_err(char *str);
void	pipe_execution(char **argv, char **env);
void	ft_output_file(char **argv, char **env, int *pipe_fd);
int		check_args(char **argv);
int		count_args(char const *s, char c);
void	multipipes(int argc, char **argv, char **env);
int		check_open_in(char *str);
void	pipeline_exec(char **argv, char **env);

#endif