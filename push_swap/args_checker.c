/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:45:01 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/07 20:34:17 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_checker(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (check_numbers(argc, &argv[i]) == 0)
			i++;
		else
		{
			write(1, "ERROR.\n", 7);
			exit (1);
		}
		return (1);
	}
	return (0);
}
