/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:24:51 by rvan-den          #+#    #+#             */
/*   Updated: 2023/02/28 13:55:32 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *stash;
	char *line;

	line = NULL;
	read_n_stash(fd, &stash);
	line = extract_line(&stash, &line);
	return (line);
}

void	read_n_stash(int fd, char **stash)
{
	char *buf;
	int i;
	size_t is_read;

	is_read = 1;
	i = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (is_read != 0)
	{	
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

char *extract_line(char **stash, char **line)
{
	int i;

	i = -1;
    char *pos;
	pos = *stash;
    while (*pos && *pos != '\n' )
        pos++;
    *line = malloc(pos - *stash + 2);
    if (*line == NULL)
        return NULL;
    while (++i < pos - *stash + 1)
        (*line)[i] = stash[0][i];
    (*line)[pos - *stash + 1] = '\0';
	*stash = clean_stash(*stash);
    return *line;
}
// derniere boucle while foireuse.
char	*clean_stash(char *stash)
{
	//char *stash_to_clean;
	char *temp;

	temp = stash;
	while (*temp != '\n')
		temp++;
	temp++;
	stash = ft_strdup(temp);
	/*free(stash[0]);
	*stash = stash_to_clean;*/
	return (stash);
}
