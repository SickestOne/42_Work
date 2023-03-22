/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:26:42 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/22 22:46:57 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quotes_checker(int argc, char **str, int i)
{
	char **temp;

	temp = ft_split(*str, ' ');
	while (temp[i])
	{
		if (i > argc)
			return (0);
		i++;
	}
	free(temp);
	return (1);
}
