/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:00:54 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/07 12:00:31 by pendejoo         ###   ########.fr       */
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

t_ctrl	*sort_for_5(t_ctrl *ab)
{
	find_move_for_5(ab);
	find_move_for_4(ab);
	sort_for_3(ab);
	go_top_a(ab);
	swap_b(ab, 1);
	push_a(ab, 1);
	push_a(ab, 1);
	go_top_a(ab);
	return (ab);
}

t_ctrl	*sort_small(t_ctrl *ab, int len)
{
	if (len == 2)
	{
		if (ab->a->data > ab->a->next->data)
			swap_a(ab, 1);
	}
	else if (len == 3)
		sort_for_3(ab);
	else if (len == 4)
	{
		find_move_for_4(ab);
		sort_for_3(ab);
		push_a(ab, 1);
	}
	else if (len == 5)
		sort_for_5(ab);
	return (ab);
}
