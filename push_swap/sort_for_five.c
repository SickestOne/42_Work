/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:00:54 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/05 19:33:32 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ctrl	*sort_for_3(t_ctrl *ab)
{
	if (ab->a->data > ab->a->next->data 
			&& ab->a->next->data > ab->a->next->next->data 
			&& ab->a->data > ab->a->next->next->data)
	{
		swap_a(ab, 1);
		rra(ab, 1);
	}
	else if (ab->a->data > ab->a->next->data
			&& ab->a->next->data < ab->a->next->next->data
			&& ab->a->data < ab->a->next->next->data)
		swap_a(ab, 1);
	else if (ab->a->data < ab->a->next->data
			&& ab->a->next->data > ab->a->next->next->data
			&& ab->a->data < ab->a->next->next->data)
	{
		swap_a(ab, 1);
		rotate_a(ab, 1);
	}
	else if (ab->a->data > ab->a->next->data
			&& ab->a->data > ab->a->next->next->data
			&& ab->a->next->data < ab->a->next->next->data)
		rotate_a(ab, 1);
	else 
		sort_for_3_p2(ab);
	return (ab);
}

t_ctrl	*sort_for_3_p2(t_ctrl *ab)
{
	if (ab->a->data > ab->a->next->next->data
			&& ab->a->next->data > ab->a->data
			&& ab->a->next->data > ab->a->next->next->data)
		rra(ab, 1);
	return (ab);
}

int	find_min(t_ctrl *ab)
{
	int tmp;
	int	pos;
	int fin_pos;

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

void	find_move(t_ctrl *ab)
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

t_ctrl	*sort_for_5(t_ctrl *ab)
{
	int i;

	i = 0;
	while (i != 2)
	{
		find_move(ab);
		i++;
	}
	sort_for_3(ab);
	go_top_a(ab);
	swap_b(ab, 1);
	push_a(ab, 1);
	push_a(ab, 1);
	go_top_a(ab);
	return (ab);
}
