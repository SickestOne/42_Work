/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:07:30 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/25 20:00:13 by pendejoo         ###   ########.fr       */
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
		first = ft_atoi(str[i]);
		second = ft_atoi(str[j]);
		if (first < second)
			sorted++;
		first = 0;
		second = 0;
		i++;
		j++;
	}
	if (sorted + 1 == argc - 1)
		return (0);
	return (1);
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
