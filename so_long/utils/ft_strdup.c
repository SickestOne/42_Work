/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:46:19 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/03 15:51:52 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(char *s1)
{
	char	*dst;
	int		i;

	i = ft_strlen(s1);
	dst = malloc(sizeof(char) * i + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, i + 1);
	return (dst);
}
