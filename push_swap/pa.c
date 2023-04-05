/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:40:31 by pendejoo          #+#    #+#             */
/*   Updated: 2023/04/05 19:20:56 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ctrl	*push_a(t_ctrl *ab, int i)
{
	int node_count_b;
	int tmp_data;
	t_node *tmp_cell;

	node_count_b = count_nodes_b(ab);
	if (node_count_b == 0)
		return (ab);
	tmp_cell = ab->b;
	tmp_data = ab->b->data;
	ab = push_a_link_last(ab, tmp_data);
	ab = push_a_clean_b(ab, node_count_b);
	free (tmp_cell);
	tmp_cell = NULL;
	if (i == 1)
	{
		write (1, "pa\n", 3);
		go_top_b(ab);
		return (ab);
	}
	go_top_b(ab);
	return (ab);
}

t_ctrl *push_a_link_last(t_ctrl *ab, int tmp_data)
{
	if (ab->a == NULL)
		ab->a = create_cell(tmp_data);
	else
	{
		while (ab->a->prev != NULL)
			ab->a = ab->a->prev;
		ab->a->prev = create_cell(tmp_data);
		ab->a->prev->next = ab->a;
		go_top_a(ab);
	}
	return (ab);
}

t_ctrl	*push_a_clean_b(t_ctrl *ab, int node_count_b)
{
	if (node_count_b > 1)
	{
		ab->b = ab->b->next;
		ab->b->prev = NULL;
	}
	else
		ab->b = NULL;
	return (ab);
}
