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

int	main(int argc, char **argv, char **env)
{
	if (argc < 3)
		exit(0);
	else if (argc == 4)
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
		dup2(pipe_fd[1], 1);		// intput file
		close(pipe_fd[0]);
		exec_cmd(argv[1], env);
	}
	waitpid(forked, NULL, 0);
	ft_output_file(argv, env, pipe_fd);
	// dup2(pipe_fd[0], 0);			// output file
	// close(pipe_fd[0]);
	// close(pipe_fd[1]);
	// exec_cmd(argv[2], env);
}

void	ft_output_file(char **argv, char **env, int *pipe_fd)
{
	int	output;
	char *file;

	file = argv[3];
	output = open(file, O_RDONLY | O_CREAT, 0777);
	if (output == -1)
		exit(0);
	dup2(output, 1);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	exec_cmd(argv[2], env);
}
