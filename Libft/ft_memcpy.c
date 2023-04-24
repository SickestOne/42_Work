/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:47:11 by rvan-den          #+#    #+#             */
/*   Updated: 2022/11/10 17:18:02 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*p_dest;
	const char	*p_src;

	if (!dst && !src)
		return (NULL);
	p_dest = dst;
	p_src = src;
	i = 0;
	while (n--)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dst);
}
