/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:27:29 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/29 11:55:47 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// test de boucler en utilisant un seul pipe.
// argv[1] etant le infile, argv[argv - 1] etant le outfile
// boucler tant que tout les args entre in et out n'ont pas ete executes

void	multipipes(int argc, char **argv, char **env)
{
	int		infile_fd;
	int		outfile_fd;

	infile_fd = check_open_in(argv[1]);
	outfile_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (infile_fd < 0 || outfile_fd < 0)
		exit(2);
}

void	pipeline_exec(char **argv, char **env)
{
	pid_t	forked;
	int	pipe_fds[2];
}

