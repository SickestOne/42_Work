/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:49:31 by pendejoo          #+#    #+#             */
/*   Updated: 2023/04/02 13:52:57 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ctrl	*rotate_a(t_ctrl *ab, int i)
{
	int node_count_a;
	int tmp_data;
	t_node *tmp_cell;

	node_count_a = count_nodes_a(ab);
	if (node_count_a < 2)
		return (ab);
	tmp_cell = ab->a;
	tmp_data = ab->a->data;
	rotate_a_linklast(ab, tmp_data);
	ab->a = ab->a->next;
	ab->a->prev = NULL;
	free (tmp_cell);
	tmp_cell = NULL;
	if (i == 1)
	{
		write (1, "ra\n", 3);
		go_top_a(ab);
		return (ab);
	}
	go_top_a(ab);
	return (ab);
}

t_ctrl	*rotate_a_linklast(t_ctrl *ab, int tmp_data)
{
	while (ab->a->next != NULL)
		ab->a = ab->a->next;
	ab->a->next = create_cell(tmp_data);
	ab->a->next->prev = ab->a;
	go_top_a(ab);
	return (ab);
}

t_ctrl	*rotate_b(t_ctrl *ab, int i)
{
	int node_count_b;
	int tmp_data;
	t_node *tmp_cell;

	node_count_b = count_nodes_b(ab);
	if (node_count_b < 2)
		return (ab);
	tmp_cell = ab->b;
	tmp_data = ab->b->data;
	rotate_b_linklast(ab, tmp_data);
	ab->b = ab->b->next;
	ab->b->prev = NULL;
	free (tmp_cell);
	tmp_cell = NULL;
	if (i == 1)
	{
		write (1, "ra\n", 3);
		go_top_b(ab);
		return (ab);
	}
	go_top_b(ab);
	return (ab);
}

t_ctrl	*rotate_b_linklast(t_ctrl *ab, int tmp_data)
{
	while (ab->b->next != NULL)
		ab->b = ab->b->next;
	ab->b->next = create_cell(tmp_data);
	ab->b->next->prev = ab->b;
	go_top_b(ab);
	return (ab);
}

t_ctrl	*r_r(t_ctrl *ab)
{
	rotate_a(ab, 0);
	rotate_b(ab, 0);
	write (1, "rr\n", 3);
	return (ab);
}
