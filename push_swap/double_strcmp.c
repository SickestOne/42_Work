/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_strcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:48:51 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/10 12:35:23 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
* modif fonction pour double_checker.
*/

int	double_strcmp(int argc, char **str)
{
	int	i;
	int j;
	int k;
	char **temp;

	i = 1;
	j = 0;
	k = 1;
	while (str[i])
	{
		while (str[i][j] && i != argc - 1)
		{
			temp = str;
			while (temp[k][k] && str[i][j])
			{
				if (argc  == 2)
					return (1);
				if ((str[i + 1][j] < temp[k][j] || str[i + 1][j] > temp[k][j]))
					j++;
				else if ((str[i + 1][j] == '\0')) 
					break;
				else
					return (0);
			}
			j = 0;
			i++;
		}
		i = 0;
		k++;
		i = k;
		temp = NULL;
	}
	return (1);
}
