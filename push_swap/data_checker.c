/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:45:42 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/07 21:07:13 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// plus et moins
#include "push_swap.h"

int	data_checker(char *str)
{
	int i;
	char **temp;
	
	temp = malloc(sizeof(str - str + 1));
	if (!temp)
		return (0);
	i = 0;
	while (temp[i])
	{
		if (!(((*temp[i] >= '0') && (*temp[i] <= '9')) || *temp[i] == '+' || *temp[i] == '-'))
			return (0);
		else if (!(*temp[i - 1] == '"' && ft_isdigit(temp[i]) && *temp[i + 1] == '"') ||
				(ft_isdigit(temp[i - 1]) && *temp[i + 1] == '"'))
			return (0);
		i++;
	}
	return (1);
}

int ft_isdigit(char *str)
{
	int i;

	i = 0;
	if ((((str[i] >= '0') && (str[i] <= '9')) || str[i] == '+' || str[i] == '-'))
		return (1);
	else
		return (0);
}
