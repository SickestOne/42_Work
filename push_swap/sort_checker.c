/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:07:30 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/25 01:11:44 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	sort_checker(int argc, char **str, int i, int j)
{
	int	first;
	int second;
	int sorted;
	int length;

	sorted = 0;
	length = argc - 1;
	while (str[i])
	{
		first = ft_atoi(str[++i]);
		second = ft_atoi(str[++j]);
		while (str[j])
		{
			if (second > first)
			{
				sorted++;
				break;
			}
		break;
		}
		first = 0;
		second = 0;
		i++;
		j++;
	}
	if (sorted >= length)
		return (0);
	return (1);
}
