/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:02:56 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/17 17:34:00 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//lire com sort_big_utils.c
t_ctrl *move_big(t_ctrl *ab)
{
	int total_len;
	int cut_coef;
	int loop_var;
	int i;

	total_len = count_nodes_a(ab);
	ab = give_ranks(ab, 0);
	cut_coef = 2;
	loop_var = total_len;
	if (count_nodes_a(ab) >= 100)
		cut_coef = cut_coef + total_len / 100 + 1;
	i = cut_coef;
	while (i != 0)
	{
		put_maxs_in_b(ab, total_len, cut_coef, &loop_var);
		fill_a(ab, 0, 0);
		go_top_a(ab);
		combine_sorted_stacks(ab, cut_coef);
		go_top_a(ab);
		i--;
	}
	return (ab);
}

void	put_maxs_in_b(t_ctrl *ab, int total_len, int cut_coef, int *loop_var)
{
	static int inter_max;
	static int i = 0;
	int inter_min;

	inter_min = *loop_var - total_len / cut_coef;
	if (i == 0)
		inter_max = total_len;
	else
		inter_max = *loop_var;
	while ((count_nodes_b(ab)) != (inter_max - inter_min))
		fill_b(ab, inter_max, inter_min);
	fill_b_opti(ab, inter_max, inter_min, total_len);
	i++;
	*loop_var = inter_min;
}

void	fill_a(t_ctrl *ab, int inter_max, int inter_min)
{
	(void)inter_max;
	(void)inter_min;
	while (count_nodes_b(ab) != 0)
	{
		if (find_max_b(ab) == ab->b->data)
			push_a(ab, 1);
		else if (find_min_pos_b(ab) == 1)
		{
			push_a(ab, 1);
			rotate_a(ab, 1);
		}
		else
			rotate_b(ab, 1);
	}
}

void	combine_sorted_stacks(t_ctrl *ab, int cut_coef)
{
	static int i = 0;
	while (ab->a->data > ab->a->next->data)
		rra(ab, 1);
	rra(ab, 1);
	i++;
	if (i == cut_coef)
	{
		while (ab->a->data < ab->a->next->data)
			rra(ab, 1);
		rotate_a(ab, 1);
	}
}
