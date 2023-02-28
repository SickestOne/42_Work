/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:24:51 by rvan-den          #+#    #+#             */
/*   Updated: 2023/02/28 11:13:47 by pendejoo         ###   ########.fr       */
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
	if (fd == -1 || !buf || BUFFER_SIZE <= 0)
		return;
	while (is_read != 0)
	{	
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		is_read = read(fd, buf, BUFFER_SIZE);
		*stash = ft_strjoin(*stash, buf);
		if (is_newline(*stash))
			break;
	}
}

int	is_newline(char *stash)
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

// presque fonctionnel, doit encore free la stash, enlever le '\n' sur le reste de la stash.
// ligne bien crop.

char *extract_line(char *stash, char **line)
{
	int i;

	i = -1;
    char *pos;
	pos = stash;
    while (*pos != '\n' && *pos)
        pos++;
    *line = malloc(pos - stash + 2);
    if (*line == NULL)
        return NULL;
    while (++i < pos - stash + 1)
        (*line)[i] = stash[i];
    (*line)[pos - stash + 1] = '\0';
	clean_stash(&stash);
    return *line;
}
// derniere boucle while foireuse.
void clean_stash(char **stash)
{
	char *stash_to_clean;
	size_t i;

	stash_to_clean = *stash;
	*stash = '\0';
	while (*stash_to_clean)
	{
		if (*stash_to_clean == '\n')
		{
			stash_to_clean++;
			i = ft_strlen(stash_to_clean);
			stash_to_clean[i + 1] = '\0';
			*stash = stash_to_clean;
			(*stash)[i + 1] = '\0';
			break;
		}
		stash_to_clean++;
	}
}
