/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:22:48 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/19 23:11:14 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_b(t_ctrl *ab, int inter_max, int inter_min)
{
	while (a_has_rank(ab, inter_max, inter_min) != 1)
	{
		if (ab->a->rank >= inter_min && ab->a->rank <= inter_max)
			push_b(ab, 1);
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
