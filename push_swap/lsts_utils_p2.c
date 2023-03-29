/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts_utils_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:10:58 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/29 15:18:04 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nodes(t_ctrl *ab)
{
	int i;

	i = 0;
	while (ab->a->prev != NULL)
	{
		ab->a = ab->a->prev;
		i++;
	}
	i++;
	printf("Number of nodes : %d\n", i);
	return (0);
}
