/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:24:51 by rvan-den          #+#    #+#             */
/*   Updated: 2023/02/24 16:04:30 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *stash;
	char *line;

	line = NULL;
	read_n_stash(fd, &stash, &line);
	return (line);
}

void	read_n_stash(int fd, char **stash, char **line)
{
	char *buf;
	int i;
	size_t is_read;

	is_read = 1;
	i = 0;
	while (is_read != 0)
	{	
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		is_read = read(fd, buf, BUFFER_SIZE);
		*stash = ft_strjoin(*stash, buf);
		if (is_newline(*stash))
				extract_line(*line, *stash);
	}
}

int	is_newline(char *stash)
{
	int i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	extract_line(char *line, char *stash)
{
	int i;
	char *temp_line;

	i = 0;
	temp_line = NULL;
	temp_line = malloc(sizeof(stash + 1));
	temp_line = stash;
}

