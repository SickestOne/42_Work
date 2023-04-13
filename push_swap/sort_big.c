/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:02:56 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/13 22:18:36 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ctrl *move_big(t_ctrl *ab)
{
	int total_len;
	int loop_var;
	int cut_coef;

	total_len = count_nodes_a(ab);
	loop_var = total_len;
	give_ranks(ab, 1);
	cut_coef = 2;
	if (count_nodes_a(ab) >= 100)
		cut_coef = cut_coef + total_len / 100 + 1;
	while (count_nodes_b(ab) != total_len / cut_coef)
	{
		if (ab->a->rank > loop_var - total_len / cut_coef)
			push_b(ab, 1);
		else
			rotate_a(ab, 1);
	}
	while (count_nodes_b(ab) != 0)
	{
		if (find_max_b(ab) == ab->b->data)
			push_a(ab, 1);
		else if (find_min_b(ab) == 1)
		{
			push_a(ab, 1);
			rotate_a(ab, 1);
		}
		else
			rotate_b(ab, 1);
	}
	go_top_a(ab);
	while (ab->a->data < ab->a->next->data)
		rotate_a(ab, 1);
	rotate_a(ab, 1);
	go_top_a(ab);
	return (ab);
}
