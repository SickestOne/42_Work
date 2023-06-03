/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:07:00 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/03 15:36:31 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
