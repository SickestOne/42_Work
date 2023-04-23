/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:28:38 by rvan-den          #+#    #+#             */
/*   Updated: 2022/11/08 11:02:36 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	j = 0;
	while (j < dstsize && dst[j])
		j++;
	dstlen = j;
	srclen = ft_strlen(src);
	if (dstsize == 0 || dstsize <= dstlen)
		return (dstsize + srclen);
	while (src[i] && i < dstsize - dstlen - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (dstlen + srclen);
}
