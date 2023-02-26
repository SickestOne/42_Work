/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:24:51 by rvan-den          #+#    #+#             */
/*   Updated: 2023/02/26 16:45:01 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *stash;
	char *line;

	line = NULL;
	read_n_stash(fd, &stash);
	line = extract_line(stash, &line);
	return (line);
}

void	read_n_stash(int fd, char **stash)
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
			break;		// ecris une fonction pour extraire la ligne.
	}
}

int	is_newline(char *stash)			// possible de lui donner plus de taff a faire ?
{
	int i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i++])
		if (stash[i] == '\n')
			return (1);
	return (0);
}

// mesurer string -> '\n', mesure string complete
// mettre string au '\n' dans la line
// mettre le reste de la string entre le '\n' et la fin de la string dans la stash

char *extract_line(char *stash, char **line)
{
	int pos;
	int i;

	pos = 0;
	i = 0;
	while (stash[i++])
		if (stash[pos - 1] != '\n')
			pos++;
	return (*line);
}

