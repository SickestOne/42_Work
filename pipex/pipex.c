/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den < rvan-den@student.42mulhouse.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:33:46 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/24 09:42:48 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// pid_t == typdedef sur type int
// pipe(pipe_fd[2]) -> deux fd, un pour lentree du pipe, un pour la sortie du pipe

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	// if (argc < 2)
	// 	exit(0);
	// char *ret = ft_execpath(argv[1], env);
	// printf("%s\n", ret);
	char *cmd = "ls -la";
	exec_cmd(cmd, env);
	return (0);
}
