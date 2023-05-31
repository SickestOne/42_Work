/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_p2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:19:42 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/31 09:48:44 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_args(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		if (count_args(argv[i], ' ') == 0)
			return (0);
	return (1);
}

int	count_args(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!*s)
		return (0);
	while (s[i + 1])
	{
		if ((s[i] == c && s[i + 1] != c) || (s[i] != c && i == '\0'))
			count++;
		i++;
	}
	return (count);
}

void	err_msg(char *cmd, int i)
{
	if (i == 1)
	{
		ft_putstr_err("pipex: command not found : ");
		ft_putstr_err(cmd);
		ft_putstr_err("\n");
	}
	if (i == 2)
	{
		ft_putstr_err("pipex: no such file or directory: ");
		ft_putstr_err(cmd);
		ft_putstr_err("\n");
	}
	if (i == 3)
	{
		(void)cmd;
		ft_putstr_err("usage : ./pipex infile cmd1 cmd2 outfile\n");
		ft_putstr_err("usage bonus : ./pipex infile cmdx ... cmdx outfile\n");
	}
}
