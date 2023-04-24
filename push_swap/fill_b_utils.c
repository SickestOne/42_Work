/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:03:43 by pendejoo          #+#    #+#             */
/*   Updated: 2023/04/21 23:38:15 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	locate_rank(t_ctrl *ab, int inter_min, int inter_max)
{
	int	pos;

	pos = 1;
	while (ab->a->next != NULL)
	{
		if (ab->a->rank >= inter_min && ab->a->rank <= inter_max)
			return (pos);
		pos++;
		ab->a = ab->a->next;
	}
	go_top_a(ab);
	return (pos);
}

void	rank_top(t_ctrl *ab, int i, int inter_min, int inter_max)
{
	i = locate_rank(ab, inter_min, inter_max);
	while (i != 1)
	{
		rotate_a(ab, 1);
		i--;
	}
	push_b(ab, 1);
}

void	rank_bot(t_ctrl *ab, int i, int inter_min, int inter_max)
{
	i = locate_rank(ab, inter_min, inter_max);
	while (i != count_nodes_a(ab))
	{
		rra(ab, 1);
		i++;
	}
	rra(ab, 1);
	push_b(ab, 1);
}
