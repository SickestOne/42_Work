/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:47:08 by pendejoo          #+#    #+#             */
/*   Updated: 2023/04/16 21:04:17 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ctrl	*rrb(t_ctrl *ab, int i)
{
	t_node	*tmp_cell;
	int	tmp_data;
	int	node_count_b;
	int tmp_rank;

	node_count_b = count_nodes_b(ab);
	if (node_count_b < 2)
		return (ab);
	go_down_b(ab);
	tmp_cell = ab->b;
	tmp_data = ab->b->data;
	tmp_rank = ab->b->rank;
	go_top_b(ab);
	ab->b->prev = create_cell(tmp_data, tmp_rank);
	ab->b->prev->next = ab->b;
	ab->b = ab->b->prev;
	clean_down_b(ab);
	free (tmp_cell);
	tmp_cell = NULL;
	if (i == 1)
	{
		write (1, "rrb\n", 4);
		go_top_b(ab);
		return (ab);
	}
	return (ab);
}

t_ctrl	*go_down_b(t_ctrl *ab)
{
	while (ab->b->next != NULL)
		ab->b = ab->b->next;
	return (ab);
}

t_ctrl	*clean_down_b(t_ctrl *ab)
{
	go_down_b(ab);
	ab->b = ab->b->prev;
	ab->b->next = NULL;
	go_top_b(ab);
	return (ab);
}
