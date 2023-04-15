/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:27:53 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/15 21:36:08 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ctrl	*push_b(t_ctrl *ab, int i)
{
	int node_count_a;
	int tmp_data;
	t_node *tmp_cell;

	node_count_a = count_nodes_a(ab);
	if (node_count_a == 0)
		return (ab);
	tmp_cell = ab->a;
	tmp_data = ab->a->data;
	push_b_link_last(ab, tmp_data);
	push_b_clean_a(ab, node_count_a);
	free (tmp_cell);
	tmp_cell = NULL;
	if (i == 1)
	{
		write (1, "pb\n", 3);
		go_top_a(ab);
		return (ab);
	}
	go_top_a(ab);
	return (ab);
}

t_ctrl *push_b_link_last(t_ctrl *ab, int tmp_data)
{
	if (ab->b == NULL)
		ab->b = create_cell(tmp_data);
	else
	{
		while (ab->b->prev != NULL)
			ab->b = ab->b->prev;
		ab->b->prev = create_cell(tmp_data);
		ab->b->prev->next = ab->b;
		go_top_b(ab);
	}
	return (ab);
}

t_ctrl	*push_b_clean_a(t_ctrl *ab, int node_count_a)
{
	if (node_count_a > 1)
	{
		ab->a = ab->a->next;
		ab->a->prev = NULL;
	}
	else
		ab->a = NULL;
	return (ab);
}
