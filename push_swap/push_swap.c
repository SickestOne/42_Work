/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:15:18 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/21 20:57:05 by pendejoo         ###   ########.fr       */
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
		build_stack(argc, argv, 1);
	return (0);
}
