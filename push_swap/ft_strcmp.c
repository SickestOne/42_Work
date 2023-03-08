/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:48:51 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/08 20:02:53 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
* modif fonction pour double_checker.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	while ((s1[index] || s2[index]))
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
