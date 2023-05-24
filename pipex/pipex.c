/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den < rvan-den@student.42mulhouse.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:33:46 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/24 15:00:16y rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// pid_t == typdedef sur type int
// pipe(pipe_fd[2]) -> deux fd, un pour lentree du pipe, un pour la sortie du pipe

int	main(int argc, char **argv, char **env)
{
	if (argc < 3)
		exit(0);
	else if (argc == 3)
		pipe_execution(argv, env);
	return (0);
}
void	pipe_execution(char **argv, char **env)
{
	int	pipe_fd[2];
	pid_t	forked;

	if (pipe(pipe_fd) == -1)
		exit(0);
	forked = fork();
	if (forked < 0)
		exit(0);
	if (forked == 0)
	{
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exec_cmd(argv[1], env);
	}
	waitpid(forked, NULL, 0);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	exec_cmd(argv[2], env);
}
