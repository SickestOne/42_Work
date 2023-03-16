/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:15:18 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/16 14:06:53 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


int	main(int argc,char **argv)
{

	if (argc < 2)
	{
		exit (0);
	}
	if (data_checker(argc, argv))
	{
		node_init(argv);
	}
	return (0);
}
