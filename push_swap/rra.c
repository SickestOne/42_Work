/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:15:03 by pendejoo          #+#    #+#             */
/*   Updated: 2023/04/16 17:33:17 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ctrl	*rra(t_ctrl *ab, int i)
{
	t_node	*tmp_cell;
	int	tmp_data;
	int	node_count_a;

	node_count_a = count_nodes_a(ab);
	if (node_count_a < 2)
		return (ab);
	go_down_a(ab);
	tmp_cell = ab->a;
	tmp_data = ab->a->data;
	go_top_a(ab);
	ab->a->prev = create_cell(tmp_data, 0);
	ab->a->prev->next = ab->a;
	ab->a = ab->a->prev;
	clean_down_a(ab);
	free (tmp_cell);
	tmp_cell = NULL;
	if (i == 1)
	{
		write (1, "rra\n", 4);
		go_top_a(ab);
		return (ab);
	}
	return (ab);
}

t_ctrl	*go_down_a(t_ctrl *ab)
{
	while (ab->a->next != NULL)
		ab->a = ab->a->next;
	return (ab);
}

t_ctrl	*clean_down_a(t_ctrl *ab)
{
	go_down_a(ab);
	ab->a = ab->a->prev;
	ab->a->next = NULL;
	go_top_a(ab);
	return (ab);
}

t_ctrl	*rrr(t_ctrl *ab)
{
	rra(ab, 0);
	rrb(ab, 0);
	write (1, "rrr\n", 4);
	return (ab);
}
