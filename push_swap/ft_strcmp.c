/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:48:51 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/09 17:44:30 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
* modif fonction pour double_checker.
*/

int	ft_strcmp(int argc, char **str)
{
	int	i;
	int j;
	int k;
	char **temp;

	i = 1;
	j = 0;
	k = 1;
	temp = str;
	while (str[i] && k < argc)
	{
		while (str[i][j])
		{
			if (argc  == 2)
				return (1);
			else if ()
				return (0);
			else
				j++;
		}
		j = 0;
		i++;
		k++;
	}
	return (1);
}
