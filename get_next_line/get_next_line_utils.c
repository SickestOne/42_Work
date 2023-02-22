/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:12:58 by rvan-den          #+#    #+#             */
/*   Updated: 2023/02/22 13:18:54 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *stashed, char *buf)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!buf)
		return (NULL);
	if (!stashed)
		return (ft_strdup(buf));
	dest = malloc(sizeof(char) * ft_strlen(stashed) + ft_strlen(buf) + 1);
		return (NULL);
	if (!dest)
		return (NULL);
	while (stashed[i])
	{
		dest[i] = stashed[i];
		i++;
	}
	while (buf[j])
	{
		dest[i] = buf[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	buf = stashed;
	return (dest);
}
char	*ft_strdup(char *s1)
{
	char	*dst;
	int		i;
	int		j;

	j = -1;
	i = ft_strlen(s1);
	dst = malloc(sizeof(char) * i + 1);
	if (!dst)
		return (NULL);
	while (s1[++j])
		dst[j] = s1[j];
	dst[j] = '\0';
	return (dst);
}
