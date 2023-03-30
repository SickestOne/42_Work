/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:27:53 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/30 19:04:13 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ctrl	*push_b(t_ctrl *ab, int i)
{
	int node_count;
	int tmp_data;
	t_node *tmp_cell;

	node_count = count_nodes_a(ab);
	if (node_count == 0)
		return (ab);
	tmp_data = ab->a->data;
	if (ab->b == NULL)
		ab->b = create_cell(tmp_data);
	else
		ab->b->prev = create_cell(tmp_data);
	tmp_cell = ab->a;
	ab->a = ab->a->next;
	ab->a->prev = NULL;
	free (tmp_cell);
	tmp_cell = NULL;
	if (i == 1)
	{
		write (1, "pb\n", 3);
		return (ab);
	}
	return (ab);
}

t_ctrl	*push_a(t_ctrl *ab, int i)
{
	int node_count;
	int tmp_data;
	t_node *tmp_cell;

	node_count = count_nodes_a(ab);
	if (node_count == 0)
		return (ab);
	tmp_data = ab->b->data;
	if (ab->a == NULL)
		ab->a = create_cell(tmp_data);
	else
		ab->a->prev = create_cell(tmp_data);
	tmp_cell = ab->b;
	ab->b = ab->b->next;
	ab->b->prev = NULL;
	free (tmp_cell);
	tmp_cell = NULL;
	if (i == 1)
	{
		write (1, "pb\n", 3);
		return (ab);
	}
	return (ab);
}
