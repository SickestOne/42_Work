/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:45:42 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/08 12:11:41 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// plus et moins
#include "push_swap.h"

int	data_checker(const char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (((str[i] >= '0') && (str[i] <= '9')) || str[i] == '+' || str[i] == '-' || (str[i] == '"'))
			return (1);
		i++;
	}
	return (0);
}

int data_checker_two(const char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (((str[i] >= '0') && (str[i] <= '9')) || str[i] == '+' || str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}
