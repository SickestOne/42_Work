/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den < rvan-den@student.42mulhouse.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:33:46 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/25 15:22:13 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (argc != 5)
	{
		write (2, "pipex : Bad usage -> file1 cmd1 cmd2 file2\n", 43);
		exit(0);
	}
	pipe_execution(argv, env);
	return (0);
}

void	pipe_execution(char **argv, char **env)
{
	pid_t	forked;
	char	*file_in;
	int		input;
	int		pipe_fd[2];

	file_in = argv[1];
	if (pipe(pipe_fd) == -1)
		exit(0);
	forked = fork();
	if (forked < 0)
		exit(0);
	if (forked == 0)
	{
		input = open(file_in, O_RDONLY, 0644);
		if (input == -1)
			exit(0);
		dup2(input, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		exec_cmd(argv[2], env);
	}
	waitpid(forked, NULL, 0);
	close(pipe_fd[1]);
	ft_output_file(argv, env, pipe_fd);
}

void	ft_output_file(char **argv, char **env, int *pipe_fd)
{
	int		output;
	char	*file;

	file = argv[4];
	output = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (output == -1)
		exit(0);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	close(pipe_fd[1]);
	close(output);
	exec_cmd(argv[3], env);
}
