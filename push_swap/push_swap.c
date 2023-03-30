/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:15:18 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/30 21:07:24 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


int	main(int argc,char **argv)
{
	if (argc < 2)
		exit (0);
	if (check_stack(argc, argv) == 2)
		chose_sort_sa(argc, argv);
	else if (check_stack(argc, argv) == 1)
		// chose_sort_ma(argc, argv);
		return (0);
	return (0);
}
