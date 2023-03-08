/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:45:42 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/08 20:12:48 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// plus et moins
#include "push_swap.h"

int	letter_checker(char **str)
{
	int i;
	int j;
	
	i = 1;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (((str[i][j] >= '0') && (str[i][j] <= '9')) || str[i][j] == '+' || str[i][j] == '-' ||
			str[i][j] == ' ')
				j++;
			else
			{
				write(2, "Error\n", 7);
				exit (2);
			}
		}
		i++;
		j = 0;
	}
	return (1);
}

int	double_checker(char **str)
{
	int tab;
	int lettre;

	tab = 1;
	lettre = 0;
	while(str[tab])
	{
		ft_strcmp(str[tab], str[lettre]);
		tab++;
	}
	return (0);
}

int	data_checker(char **str)
{
	if (!(letter_checker(str) || !double_checker(str)))
		return (0);
	else
		return (1);
}
