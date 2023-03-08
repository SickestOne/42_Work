/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:45:01 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/08 12:18:54 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_checker(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (data_checker(argv[i]) == 0)
		{
			write(1, "ERROR.\n", 7);
			exit (1);
		}
		i++;
	}
	return (1);
}
