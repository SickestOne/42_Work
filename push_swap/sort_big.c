/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:02:56 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/14 16:40:40 by rvan-den         ###   ########.fr       */
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
	while (a_is_sorted(ab) < 1)
	{
		put_maxs_in_b(ab, total_len, cut_coef, loop_var);
		fill_a(ab);
		go_top_a(ab);
		combine_sorted_stacks(ab);
		go_top_a(ab);
	}
	return (ab);
}

void	put_maxs_in_b(t_ctrl *ab, int total_len, int cut_coef, int loop_var)
{
	int inter_max;
	int inter_min;

	inter_min = loop_var - total_len / cut_coef;
	inter_max = total_len;
	while (count_nodes_b(ab) != total_len / cut_coef)
	{
		if (ab->a->rank > inter_min && ab->a->rank <= inter_max)
			push_b(ab, 1);
		else
			rotate_a(ab, 1);
	}
}

void	fill_a(t_ctrl *ab)
{
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
}

void	combine_sorted_stacks(t_ctrl *ab)
{
	while (ab->a->data < ab->a->next->data)
		rotate_a(ab, 1);
	rotate_a(ab, 1);
}
