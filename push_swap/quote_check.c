/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:26:42 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/23 00:09:55 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quotes_checker(char **str, int i)
{
	int params;

	while (str[i])
	{
		params = count_params(str, ' ', 0);
		if (params > 1)
			return (0);
		i++;
	}
	return (1);
}
int	count_params(char **s, char c,int i)
{
	int	count;
	int j;

	count = 0;
	j = 0;
	if (!**s)
		return (0);
	while (s[i])
	{
		while (s[i][j])
		{
			if ((s[i][j] == c && s[i][j + 1] != c) || (s[i][j] != c && i == '\0'))
				count++;
			j++;
		}
		i++;
		j = 0;
	}
	return (count);
}
