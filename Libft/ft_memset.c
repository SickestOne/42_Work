/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:53:26 by rvan-den          #+#    #+#             */
/*   Updated: 2022/11/10 17:33:54 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s_cpy;

	i = 0;
	s_cpy = b;
	while (i < len)
	{
		*s_cpy = (unsigned char)c;
		s_cpy++;
		i++;
	}
	return (b);
}
