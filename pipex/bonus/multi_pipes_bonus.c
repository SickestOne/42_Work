/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:27:29 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/31 09:48:29 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	multipipes(int argc, char **argv, char **env)
{
	int		infile_fd;
	int		outfile_fd;
	int		i;

	i = 1;
	infile_fd = check_open_in(argv[1]);
	outfile_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (infile_fd < 0 || outfile_fd < 0)
		exit(1);
	while (i < argc - 3)
		infile_fd = pipeline_exec(argv[++i], env, infile_fd);
	dup2(infile_fd, STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	exec_cmd(argv[argc - 2], env);
}

int	pipeline_exec(char *cmd_to_exec, char **env, int input)
{
	pid_t		forked;
	static int	pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		exit(2);
	forked = fork();
	if (forked < 0)
		exit(2);
	if (forked == 0)
	{
		dup2(input, STDIN_FILENO);
		dup2(pipe_fds[1], STDOUT_FILENO);
		close(pipe_fds[1]);
		close(pipe_fds[0]);
		close(input);
		exec_cmd(cmd_to_exec, env);
	}
	waitpid(forked, NULL, 0);
	close(pipe_fds[1]);
	close(input);
	return (pipe_fds[0]);
}
