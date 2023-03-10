/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:45:42 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/10 17:01:18 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}

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

int		int_checker(int argc, char **str)
{

}
int	data_checker(int argc, char **str)
{
	if (!(letter_checker(str)) || !double_strcmp(argc, str, 1, 0))
	{
		write(2, "Error\n", 7);
		exit (2);
	}
	else
		return (1);
}
