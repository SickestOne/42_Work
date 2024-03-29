/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:12:58 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/03 16:01:50 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	ft_strlen(const char *s)
// {
// 	int	len;

// 	len = 0;
// 	if (!s)
// 		return (0);
// 	while (s[len] != '\0')
// 		len++;
// 	return (len);
// }

char	*ft_strjoin(char **stash, char **buf)
{
	char	*dest;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!*buf)
		return (free_data(stash, buf));
	if (!*stash)
		return (ft_strdup(*buf));
	dest = malloc(sizeof(char) * (ft_strlen(*stash) + ft_strlen(*buf) + 1));
	if (!dest)
		return (free_data(stash, buf));
	while ((*stash)[++i])
		dest[i] = (*stash)[i];
	while ((*buf)[++j])
	{
		dest[i] = (*buf)[j];
		i++;
	}
	dest[i] = '\0';
	free_data(stash, NULL);
	return (dest);
}

// char	*ft_strdup(char *s1)
// {
// 	char	*dst;
// 	int		i;
// 	int		j;

// 	if (!s1)
// 		return (NULL);
// 	j = -1;
// 	i = ft_strlen(s1);
// 	dst = malloc(sizeof(char) * (i + 1));
// 	if (!dst)
// 		return (NULL);
// 	while (s1[++j])
// 		dst[j] = s1[j];
// 	dst[j] = '\0';
// 	return (dst);
// }

void	*free_data(char **stash, char **buf)
{
	if (buf && *buf)
	{
		free(*buf);
		*buf = NULL;
	}
	if (stash && *stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (NULL);
}
