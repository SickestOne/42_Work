/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:45:01 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/07 19:17:52 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_checker(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (check_numbers(argc, &argv[i]) != 0)
			i++;
		else
		{
			printf("Bad input detected.\n");
			exit (1);
		}
	}
}
