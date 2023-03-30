/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:47:45 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/30 21:24:56 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ctrl *swap_a(t_ctrl *ab, int i)
{
	int tmp;
	int node_count;

	node_count = count_nodes_a(ab);
	if (node_count == 1 || node_count == 0)
		return (ab);
	tmp = ab->a->data;
	ab->a->data = ab->a->next->data;
	ab->a->next->data = tmp;
	if (i == 1)
	{
		write (1, "sa\n", 3);
		return (ab);
	}
	return (ab);
}

t_ctrl *swap_b(t_ctrl *ab, int i)
{
	int tmp;
	int node_count;

	node_count = count_nodes_b(ab);
	if (node_count == 1 || node_count == 0)
		return (ab);
	tmp = ab->b->data;
	ab->b->data = ab->b->next->data;
	ab->b->prev->data = tmp;
	if (i == 1)
	{
		write (1, "sb\n", 3);
		return (ab);
	}
	return (ab);
}

t_ctrl *s_s(t_ctrl *ab)
{
	swap_a(ab, 0);
	swap_b(ab, 0);
	write (1, "ss\n", 3);
	return (ab);
}
