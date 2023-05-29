/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:33:46 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/29 17:29:14 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (argc == 5 && check_args(argv))
		pipe_execution(argv, env);
	else if (argc > 5 && check_args(argv))
		multipipes(argc, argv, env);
	else
	{
		ft_putstr_err("usage : ./pipex infile cmd1 cmd2 outfile\n");
		ft_putstr_err("usage bonus : ./pipex infile cmdx ... cmdx outfile\n");
		exit(2);
	}
	return (0);
}

void	pipe_execution(char **argv, char **env)
{
	pid_t	forked;
	int		input;
	int		pipe_fd[2];

	input = 0;
	if (pipe(pipe_fd) == -1)
		exit(2);
	forked = fork();
	if (forked < 0)
		exit(2);
	if (forked == 0)
	{
		input = check_open_in(argv[1]);
		if (input == -1)
			exit(2);
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

int	check_open_in(char *str)
{
	int	input_file;

	if (access(str, F_OK) == -1)
	{
		ft_putstr_err("pipex: no such file or directory: ");
		ft_putstr_err(str);
		ft_putstr_err("\n");
		exit(2);
	}
	input_file = open(str, O_RDONLY, 0644);
	return (input_file);
}
