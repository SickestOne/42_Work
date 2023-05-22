/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:26:54 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/22 11:15:43 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*substr_2(unsigned int start, size_t len, char const *s, char *dest)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			dest[j] = s[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	if (slen - start < len)
		len = slen - start;
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	return (substr_2(start, len, s, dest));
}
