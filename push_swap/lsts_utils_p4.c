/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts_utils_p4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:20:59 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/13 10:24:18 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	check_ranks_b(t_ctrl *ab)
{
	while (ab->b->next != NULL)
	{
		if (ab->b->rank == 0)
			return (0);
		ab->b = ab->b->next;
	}
	return (1);
}

t_ctrl	*give_ranks_b(t_ctrl *ab, int ranks)
{
	t_node *tmp;

	tmp = ab->b;
	while (check_ranks_b(ab) != 1)
	{
		while (ab->b != NULL)
		{
			if (tmp->data > ab->b->data && ab->b->rank == 0)
				tmp = ab->b;
			ab->b = ab->b->next;
		}
		ab->b = tmp;
		tmp->rank = ranks;
		ranks++;
		go_top_b(ab);
		if (check_ranks_b(ab))
			break ;
		while (ab->b->rank != 0)
			ab->b = ab->b->next;
		tmp = ab->b;
	}
	go_top_b(ab);
	return (ab);
}
