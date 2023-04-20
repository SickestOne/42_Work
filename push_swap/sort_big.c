/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:02:56 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/20 19:17:38 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ctrl	*move_big(t_ctrl *ab)
{
	int	total_len;
	int	cut_coef;
	int	loop_var;
	int	i;

	total_len = count_nodes_a(ab);
	ab = give_ranks(ab, 0);
	cut_coef = 2;
	loop_var = total_len;
	if (total_len == 100)
		cut_coef = cut_coef + total_len / 100 + 1;
	else if (total_len == 500)
		cut_coef = cut_coef * 5;
	i = cut_coef;
	while (i != 0)
	{
		put_maxs_in_b(ab, total_len, cut_coef, &loop_var);
		fill_a(ab);
		go_top_a(ab);
		combine_sorted_stacks(ab, cut_coef, total_len);
		go_top_a(ab);
		i--;
	}
	return (ab);
}

void	put_maxs_in_b(t_ctrl *ab, int total_len, int cut_coef, int *loop_var)
{
	static int	inter_max;
	static int	i = 0;
	int			inter_min;

	inter_min = *loop_var - total_len / cut_coef;
	if (i == 0)
		inter_max = total_len;
	else
		inter_max = *loop_var;
	fill_b(ab, inter_max, inter_min);
	i++;
	*loop_var = inter_min;
}

void	fill_a(t_ctrl *ab)
{
	while (count_nodes_b(ab) != 0)
	{
		if (find_max_data_b(ab) == ab->b->data)
			push_a(ab, 1);
		else if (find_min_data_b(ab) == ab->b->data)
		{
			push_a(ab, 1);
			rotate_a(ab, 1);
		}
		else
			rotate_b(ab, 1);
	}
}

void	combine_sorted_stacks(t_ctrl *ab, int cut_coef, int total_len)
{
	static int	i = 0;

	i++;
	if (total_len == 500 && (i >= cut_coef / 2 + 1) && i != cut_coef)
		combine_first_if(ab, total_len);
	else if (total_len == 500 && i == cut_coef)
	{
		go_top_a(ab);
		while (ab->a->data < ab->a->next->data)
			rra(ab, 1);
		rotate_a(ab, 1);
	}
	else if (total_len == 500 && (i != cut_coef && i < cut_coef / 2 + 1))
		in_range_500(ab);
	else if (total_len == 100 && i == cut_coef)
	{
		while (ab->a->data < ab->a->next->data)
			rra(ab, 1);
		rotate_a(ab, 1);
	}
	out_of_range(ab, cut_coef, total_len);
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
