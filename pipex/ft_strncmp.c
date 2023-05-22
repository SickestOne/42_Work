/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:48:51 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/22 14:27:25 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while ((s1[index] || s2[index]) && index < n)
	{
		if (!ft_isascii(s1[index]) || !ft_isascii(s2[index]))
			index++;
		if ((s1[index] > s2[index]) || !s2[index])
			return (1);
		if ((s1[index] < s2[index]) || !s1[index])
			return (-1);
		index++;
	}
	return (0);
}
