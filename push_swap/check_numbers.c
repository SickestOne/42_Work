/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:21:25 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/07 19:23:06 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numbers(int argc, char **argv)
{
	int i;

	i = 0;
	while (argv[i] && i < argc)
	{
		if (!ft_isdigit(argv[i]))
			break;
		i++;
	}
	return (0);
}
