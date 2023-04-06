/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_five_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:44:26 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/06 14:46:34 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_ctrl *ab)
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
	ab = go_top_a(ab);
	return (fin_pos);
}

void	find_move_for_5(t_ctrl *ab)
{
	if (find_min(ab) == 1)
		push_b(ab, 1);
	else if (find_min(ab) == 2)
	{
		swap_a(ab, 1);
		push_b(ab, 1);
	}
	else if (find_min(ab) == 3)
	{
		rotate_a(ab, 1);
		swap_a(ab, 1);
		push_b(ab, 1);
	}
	else if (find_min(ab) == 4)
	{
		rra(ab, 1);
		rra(ab, 1);
		push_b(ab, 1);
	}
	else if (find_min(ab) == 5)
	{
		rra(ab, 1);
		push_b(ab, 1);
	}
}

void	find_move_for_4(t_ctrl	*ab)
{
	if (find_min(ab) == 1)
		push_b(ab, 1);
	else if (find_min(ab) == 2)
	{
		swap_a(ab, 1);
		push_b(ab, 1);
	}
	else if (find_min(ab) == 3)
	{
		rra(ab, 1);
		rra(ab, 1);
		push_b(ab, 1);
	}
	else if (find_min(ab) == 4)
	{
		rra(ab, 1);
		push_b(ab, 1);
	}
}
