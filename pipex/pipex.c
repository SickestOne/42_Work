/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den < rvan-den@student.42mulhouse.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:33:46 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/27 13:10:26 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (argc == 5 && check_args(argv))
		pipe_execution(argv, env);
	else if (argc > 5 && check_args(argv))
		printf("in multipipes\n");
	else
	{
		write (2, "pipex : Bad usage -> file1 cmd1 cmd2 file2\n", 43);
		exit(0);
	}
	return (0);
}

void	pipe_execution(char **argv, char **env)
{
	pid_t	forked;
	char	*file_in;
	int		input;
	int		pipe_fd[2];

	input = 0;
	file_in = argv[1];
	if (pipe(pipe_fd) == -1)
		exit(0);
	forked = fork();
	if (forked < 0)
		exit(0);
	if (forked == 0)
	{
		input = check_open_in(argv);
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
		exit(2);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	close(pipe_fd[1]);
	close(output);
	exec_cmd(argv[3], env);
}

int	check_open_in(char **argv)
{
	int	input_file;

	if (access(argv[1], F_OK) == -1)
	{
		write (STDERR_FILENO, "pipex :", 7);
		ft_putstr_err(argv[1], -1);
		ft_putstr_err(": No such file or directory", -1);
		write (STDERR_FILENO, "\n", 1);
		input_file = -1;
		return (input_file);
	}
	input_file = open(argv[1], O_RDONLY, 0644);
	return (input_file);
}
