/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:08:34 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/31 09:49:21 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_getenv(char *name, char **env)
{
	int		i;
	int		j;

	i = -1;
	j = ft_strlen(name);
	while (env[++i])
		if (ft_strncmp((const char *)env[i], name, j) == 0)
			return (env[i]);
	return (NULL);
}

char	*ft_execpath(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**split_path;
	char	*path_join;
	char	**av_cmd;

	i = -1;
	split_path = ft_split(ft_getenv("PATH=", env), ':');
	av_cmd = ft_split(cmd, ' ');
	while (split_path[++i])
	{
		path_join = ft_strjoin(split_path[i], "/");
		exec = ft_strjoin(path_join, av_cmd[0]);
		free(path_join);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free_tabs(av_cmd);
			return (exec);
		}
		free(exec);
	}
	free_tabs(split_path);
	free_tabs(av_cmd);
	return (cmd);
}

int	exec_cmd(char *cmd, char **env)
{
	char	**split_argv;
	char	*path;

	split_argv = ft_split(cmd, ' ');
	path = ft_execpath(split_argv[0], env);
	if (execve(path, split_argv, env) == -1)
	{
		err_msg(cmd, 1);
		free_tabs(split_argv);
		exit(127);
	}
	return (1);
}

void	free_tabs(char **tab)
{
	int	j;

	j = -1;
	while (tab[++j])
		free(tab[j]);
	free(tab);
}

void	ft_putstr_err(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(STDERR_FILENO, &str[i], 1);
}
