/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:45:42 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/22 18:47:07 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TO DO :
// check 21---/etc
// check number of args if "xx xx xx"

int	number_checker(char **str, int i, int j)
{
	while (str[i])
	{
		while (str[i][j])
		{
			if (((str[i][j] >= '0') && (str[i][j] <= '9')) || str[i][j] == '+'
				|| str[i][j] == '-' || str[i][j] == ' ')
				j++;
			else
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}

int	sign_checker(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if ((number_checker(str, 1, 0) && str[i][j + 1] == '-')
				|| (number_checker(str, 1, 0) && str[i][j + 1] == '+'))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	double_checker(int argc, char **str, int i, int j)
{
	int	temp;

	while (str[++i])
	{
		if (argc == 2)
			return (1);
		temp = ft_atoi(str[i]);
		while (str[j])
		{
			if (i == j && j < argc - 1)
				j++;
			if (ft_atoi(str[j]) != temp)
			{
				if (j < argc - 1)
					j++;
			}
			else
				return (0);
			if (j >= argc - 1)
				break ;
		}
		j = 1;
	}
	return (1);
}

int	int_checker(char **str, int i)
{
	while (str[++i])
	{
		if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
			return (0);
		/*if (ft_strlen(str[i]) > 10)
			return (0);*/
	}
	return (1);
}

int	data_checker(int argc, char **str)
{
	if (!(number_checker(str, 1, 0)) || !double_checker(argc, str, 0, 1)
		|| !int_checker(str, -1) || !sign_checker(str))
	{
		write(2, "Error\n", 7);
		exit (2);
	}
	else
		return (1);
}
