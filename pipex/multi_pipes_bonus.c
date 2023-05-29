/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:27:29 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/29 18:32:26 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// test de boucler en utilisant un seul pipe.
// argv[1] etant le infile, argv[argv - 1] etant le outfile
// boucler tant que tout les args entre in et out n'ont pas ete executes

// dup2(outfile_fd, STDOUT_FILENO); <- a faire a la detect de time = argv[argc - 1];
// pipe_line exec argv[2];
// boucle sa mere;
void	multipipes(int argc, char **argv, char **env)
{
	int		infile_fd;
	int		outfile_fd;
	int		i;

	i = 2;
	infile_fd = check_open_in(argv[1]);
	outfile_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (infile_fd < 0 || outfile_fd < 0)
		exit(2);
	dup2(infile_fd, STDIN_FILENO);
	pipeline_exec(argv[2], env);
	while (i < argc - 2)
		pipeline_exec(argv[++i], env);
	dup2(outfile_fd, STDOUT_FILENO);
	exec_cmd(argv[argc - 2], env);
}

void	pipeline_exec(char *cmd_to_exec, char **env)
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
		close(pipe_fds[0]);
		dup2(pipe_fds[1], STDOUT_FILENO);
		exec_cmd(cmd_to_exec, env);
	}
	waitpid(forked, NULL, 0);
	close(pipe_fds[1]);
	dup2(pipe_fds[0], STDIN_FILENO);
}
