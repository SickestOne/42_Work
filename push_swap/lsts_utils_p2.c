/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts_utils_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:10:58 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/02 14:37:50 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nodes_a(t_ctrl *ab)
{
	int	i;

	i = 0;
	if (ab->a == NULL)
		return (0);
	while (ab->a->next != NULL)
	{
		ab->a = ab->a->next;
		i++;
	}
	i++;
	go_top_a(ab);
	return (i);
}

int	count_nodes_b(t_ctrl *ab)
{
	int	i;

	i = 0;
	if (ab->b == NULL)
		return (0);
	while (ab->b->next != NULL)
	{
		ab->b = ab->b->next;
		i++;
	}
	i++;
	go_top_b(ab);
	return (i);
}

t_ctrl	*go_top_a(t_ctrl *ab)
{
	if (ab->a == NULL)
		return (ab);
	while (ab->a->prev != NULL)
		ab->a = ab->a->prev;
	return (ab);
}

t_ctrl	*go_top_b(t_ctrl *ab)
{
	if (ab->b == NULL)
		return (ab);
	while (ab->b->prev != NULL)
		ab->b = ab->b->prev;
	return (ab);
}
