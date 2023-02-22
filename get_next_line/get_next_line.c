/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:46:58 by pendejoo          #+#    #+#             */
/*   Updated: 2023/02/22 15:25:13 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *stash;
	char buf[BUFFER_SIZE + 1];
	size_t readed;

	while (is_nl(stash) != 1)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		stash = ft_strjoin(stash, buf);
	}
	return (stash);
}

int	is_nl(char *stash)
{
	int is_true;
	int i;

	is_true = 0;
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			is_true = 1;
			return (1);
		}
		i++;
	}
	return (is_true);
}
