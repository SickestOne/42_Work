/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_five_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:44:26 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/21 14:17:54 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_move_for_5(t_ctrl *ab)
{
	if (find_min_5(ab) == 1)
		push_b(ab, 1);
	else if (find_min_5(ab) == 2)
	{
		swap_a(ab, 1);
		push_b(ab, 1);
	}
	else if (find_min_5(ab) == 3)
	{
		rotate_a(ab, 1);
		swap_a(ab, 1);
		push_b(ab, 1);
	}
	else if (find_min_5(ab) == 4)
	{
		rra(ab, 1);
		rra(ab, 1);
		push_b(ab, 1);
	}
	else if (find_min_5(ab) == 5)
	{
		rra(ab, 1);
		push_b(ab, 1);
	}
}

void	find_move_for_4(t_ctrl	*ab)
{
	if (find_min_5(ab) == 1)
		push_b(ab, 1);
	else if (find_min_5(ab) == 2)
	{
		swap_a(ab, 1);
		push_b(ab, 1);
	}
	else if (find_min_5(ab) == 3)
	{
		rra(ab, 1);
		rra(ab, 1);
		push_b(ab, 1);
	}
	else if (find_min_5(ab) == 4)
	{
		rra(ab, 1);
		push_b(ab, 1);
	}
}

int	find_max_5(t_ctrl *ab)
{
	int	tmp;
	int	pos;
	int	fin_pos;

	tmp = ab->a->data;
	pos = 1;
	fin_pos = 0;
	while (ab->a->next != NULL)
	{
		if (tmp < ab->a->next->data)
		{
			tmp = ab->a->next->data;
			fin_pos = pos + 1;
		}
		ab->a = ab->a->next;
		pos++;
	}
	if (fin_pos == 0)
		fin_pos++;
	ab = go_top_a(ab);
	return (fin_pos);
}

int	find_min_5(t_ctrl *ab)
{
	int	tmp;
	int	pos;
	int	fin_pos;

	tmp = ab->a->data;
	pos = 1;
	fin_pos = 0;
	while (ab->a->next != NULL)
	{
		if (tmp > ab->a->next->data)
		{
			tmp = ab->a->next->data;
			fin_pos = pos + 1;
		}
		ab->a = ab->a->next;
		pos++;
	}
	if (fin_pos == 0)
		fin_pos++;
	go_top_a(ab);
	return (fin_pos);
}
