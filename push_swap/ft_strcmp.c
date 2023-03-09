/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:48:51 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/09 18:29:54 by pendejoo         ###   ########.fr       */
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
	while (str[i])
	{
		while (str[i][j])
		{
			if (argc  == 2)
				return (1);
			else if ((str[i + 1][j] != temp[k][j] && str[i + 1][j] != '\0'))
				j++;
			else
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}
