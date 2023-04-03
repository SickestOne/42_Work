/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:00:54 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/03 18:08:02 by rvan-den         ###   ########.fr       */
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

t_ctrl	*sort_for_5(t_ctrl *ab);
