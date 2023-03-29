/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:07:30 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/29 19:41:04 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	sort_checker_ma(int argc, char **str, int i, int j)
{
	int	first;
	int second;
	int sorted;

	sorted = 0;
	while (str[i + 1])
	{
		if ((sorted + 1 == argc - 1) || ((i == argc - 1) && (sorted < i)))
			break;
		first = ft_long_atoi(str[i]);
		second = ft_long_atoi(str[j]);
		if (first < second)
			sorted++;
		first = 0;
		second = 0;
		i++;
		j++;
	}
	if (sorted + 1 == argc - 1)
		return (1);
	return (0);
}

int		sort_checker_sa(int argc, char **str)
{
	char	**temp;

	temp = ft_split((const char *)str[1], ' ');
	argc = count_params(temp, ' ', 0);
	argc++;
	if (sort_checker_ma(argc, temp, 0, 1))
		return (1);
	return (0);
}

int sorted_stack_a_sa(int argc, char **str)
{
	if (!sa_checker(str))
		return (-1);
	else if (sa_checker(str) && sort_checker_sa(argc, str))
		return (0);
	else
		return (1);
}

int sorted_stack_a_ma(int argc, char **str)
{
	if (!ma_checker(argc, str))
		return (-1);
	else if (ma_checker(argc, str) 
		&& sort_checker_ma(argc, str, 1, 2))
		return (0);
	else
		return (1);
}

int	check_solo_sign(char **str, int i)
{
	int j;

	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if ((str[i][j] == '+' || str[i][j] == '-') && (str[i][j + 1] == '\0'))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}
