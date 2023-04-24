/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:07:00 by rvan-den          #+#    #+#             */
/*   Updated: 2022/11/08 14:32:04 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	convert;

	convert = c;
	i = 0;
	while (s[i] != convert && s[i])
		i++;
	if (s[i] == convert)
		return ((char *)(s + i));
	return (NULL);
}
