/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:22:48 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/21 23:41:04 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_b(t_ctrl *ab, int inter_max, int inter_min)
{
	int	i;

	i = 0;
	while (a_has_rank(ab, inter_max, inter_min) != 1)
	{
		if (ab->a->rank >= inter_min && ab->a->rank <= inter_max)
			push_b(ab, 1);
		else if (locate_rank(ab, inter_min, inter_max) < count_nodes_a(ab) / 2)
			rank_top(ab, i, inter_min, inter_max);
		else if (locate_rank(ab, inter_min, inter_max)
			> count_nodes_a(ab) / 2 + 1)
			rank_bot(ab, i, inter_min, inter_max);
		else
			rotate_a(ab, 1);
	}
}

void	out_of_range(t_ctrl *ab, int cut_coef, int total_len)
{
	(void)cut_coef;
	if (total_len != 100 && total_len != 500)
	{
		while (ab->a->data < ab->a->next->data)
			rra(ab, 1);
		rotate_a(ab, 1);
	}
}

void	in_range_500(t_ctrl *ab)
{
	while (ab->a->data < ab->a->next->data)
		rotate_a(ab, 1);
	rotate_a(ab, 1);
}

int	a_has_rank(t_ctrl *ab, int inter_max, int inter_min)
{
	while (ab->a->next != NULL)
	{
		if (ab->a->rank >= inter_min && ab->a->rank <= inter_max)
		{
			go_top_a(ab);
			return (0);
		}
		ab->a = ab->a->next;
	}
	go_top_a(ab);
	return (1);
}
