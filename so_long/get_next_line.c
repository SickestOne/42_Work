/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:24:51 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/31 15:11:52 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	line = NULL;
	read_n_stash(fd, &stash);
	if (stash && is_newline(stash))
		line = extract_line(&stash, &line);
	else if (stash)
	{
		line = ft_strdup(stash);
		free(stash);
		stash = NULL;
	}
	if (line && *line == '\0')
	{
		free(line);
		return (NULL);
	}
	else if (!line)
		return (free_data(&stash, NULL));
	return (line);
}

void	read_n_stash(int fd, char **stash)
{
	char	*buf;
	int		is_read;

	is_read = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return ((void)free_data(stash, NULL));
	while ((is_read >= 0) && buf != NULL && fd >= 0)
	{	
		is_read = read(fd, buf, BUFFER_SIZE);
		if (is_read < 0)
			return ((void)free_data(stash, &buf));
		else if (is_read == 0)
			break ;
		buf[is_read] = '\0';
		*stash = ft_strjoin(stash, &buf);
		if (!*stash)
			return ((void)free_data(NULL, &buf));
		if (is_newline(*stash))
			break ;
	}
	free_data(NULL, &buf);
}

int	is_newline(char *stash)
{
	int	i;

	i = -1;
	if (!stash)
		return (0);
	while (stash[++i])
		if (stash[i] == '\n')
			return (1);
	return (0);
}

char	*extract_line(char **stash, char **line)
{
	int		i;
	char	*pos;

	i = -1;
	if (!*stash)
		return (NULL);
	pos = *stash;
	while (*pos && *pos != '\n')
		pos++;
	*line = malloc(sizeof(char) * (pos - *stash + 2));
	if (*line == NULL)
		return (NULL);
	while (++i < pos - *stash + 1)
		(*line)[i] = stash[0][i];
	(*line)[pos - *stash + 1] = '\0';
	*stash = clean_stash(*stash);
	return (*line);
}

char	*clean_stash(char *stash)
{
	char	*temp;
	char	*to_free;

	temp = stash;
	to_free = temp;
	while (*temp && *temp != '\n')
		temp++;
	stash = ft_strdup(++temp);
	free(to_free);
	return (stash);
}
