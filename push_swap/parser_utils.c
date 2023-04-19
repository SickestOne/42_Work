/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:45:05 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/19 17:58:36 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// UNCOMMENT L:80 FOR EVAL !!!
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

int	sign_checker(char **str, int i, int j)
{
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
	int	current;
	int	next;

	while (str[i])
	{
		if (j == argc)
			break ;
		current = ft_long_atoi(str[i]);
		next = ft_long_atoi(str[j]);
		while (str[j])
		{
			if (current == next)
				return (0);
			j++;
			if (j == argc)
				break ;
			next = ft_long_atoi(str[j]);
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	int_checker(char **str, int i)
{
	while (str[++i])
	{
		if (ft_long_atoi(str[i]) > 2147483647 ||
			ft_long_atoi(str[i]) < -2147483648)
			return (0);
		if (ft_strlen(str[i]) > 10)
			return (0);
	}
	return (1);
}

int	count_params(char **s, char c, int i)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	if (!**s)
		return (0);
	while (s[i])
	{
		while (s[i][j])
		{
			if ((s[i][j] == c && s[i][j + 1] != c) ||
				(s[i][j] != c && s[i][j + 1] == '\0'))
				count++;
			j++;
		}
		i++;
		j = 0;
	}
	if (count == 1)
		return (0);
	else
		return (count);
}
