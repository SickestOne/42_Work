/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:02:56 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/16 22:02:39 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		fill_a(ab);
		go_top_a(ab);
		combine_sorted_stacks(ab);
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
	{
		if (ab->a->rank > inter_min && ab->a->rank <= inter_max)
			push_b(ab, 1);
		else
			rotate_a(ab, 1);
	}
	i++;
	*loop_var = inter_min;
}

// fill_a needs opti (rra's ?)
// best to move, if up mediane B, ra, else rra
void	fill_a(t_ctrl *ab)
{
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

void	combine_sorted_stacks(t_ctrl *ab)
{
	while (ab->a->data < ab->a->next->data)
		rotate_a(ab, 1);
	rotate_a(ab, 1);
}

void	fill_a_opti(t_ctrl *ab)
{
	int	stack_size;

	stack_size = 0;
	while (count_nodes_b(ab) != 0)
	{
		stack_size = count_nodes_b(ab);
		if (find_max_b(ab) == ab->b->data)
			push_a(ab, 1);
		else if (find_min_pos_b(ab) == 1)
		{
			push_a(ab, 1);
			rotate_a(ab, 1);
		}
		else if (find_max_pos_b(ab) > stack_size / 2)
		{
			while (find_max_pos_b(ab) != 1)
				rotate_b(ab, 1);
			push_a(ab, 1);
		}
		else if (find_min_pos_b(ab) > stack_size / 2)
		{
			while (find_min_pos_b(ab) != 1)
				rotate_b(ab, 1);
			push_a(ab, 1);
			rotate_a(ab, 1);
		}
		else if (find_max_pos_b(ab) < stack_size / 2)
		{
			while (find_max_pos_b(ab) != stack_size)
				rrb(ab, 1);
			push_a(ab, 1);
		}
		else if (find_min_pos_b(ab) < stack_size / 2)
		{
			while (find_min_pos_b(ab) != stack_size)
				rrb(ab, 1);
			push_a(ab, 1);
			rotate_a(ab, 1);
		}
		else
			rotate_b(ab, 1);
	}
}

