/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:15:18 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/16 15:56:29 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


int	main(int argc,char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
	{
		exit (0);
	}
	if (data_checker(argc, argv))
	{
		while (argv[i])
		{
			node_init(&argv[i]);
			i++;
		}
	}
	return (0);
}
