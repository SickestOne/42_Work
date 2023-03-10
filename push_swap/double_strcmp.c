/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_strcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:48:51 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/10 16:15:33 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
* modif fonction pour double_checker.
*/

int	double_strcmp(int argc, char **str, int j, int i)
{
	int temp;

	while (str[++i])
	{
		if (argc == 2)
			return (1);
		temp = ft_atoi(str[i]);
		while (str[j])
		{
			if (i == j)
				if (j < argc - 1)
					j++;
			if (ft_atoi(str[j]) != temp)
			{
				if (j < argc - 1)
					j++;
			}
			else
				return (0);
			if (j >= argc - 1)
				break;
		}
		j = 1;
	}
	return (1);
}
