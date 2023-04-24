/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:51:41 by rvan-den          #+#    #+#             */
/*   Updated: 2022/11/10 17:37:14 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len;
	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		while (i--)
			((char *)dst)[i] = ((char *)src)[i];
	}
	else
	{
		i = 0;
		while (i != len)
		{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
		}
	}
	return (dst);
}
