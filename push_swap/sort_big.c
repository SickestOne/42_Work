/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:02:56 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/12 19:02:41 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ctrl	*move_first_20(t_ctrl *ab, int pos)
{
	int len;
	int i;

	len = count_nodes_a(ab);
	i = len / 4;
	give_ranks(ab, 1);
	while (count_nodes_b(ab) != len \ 4)
	{
		while (ab->a->next != NULL)
		{

		}
	}
	return (ab);
}

t_ctrl	*search_to_move(t_ctrl *ab, int pos)
{
	while (ab->a->next != NULL)
	{

	}
	return (ab);
}

