/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:22:48 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/14 16:40:02 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_is_sorted(t_ctrl *ab)
{
	int i;
	int check;

	i = 0;
	check = count_nodes_a(ab);
	while (ab->a->next != NULL)
	{
		if (ab->a->data < ab->a->next->data)
		{
			ab->a = ab->a->next;
			i++;
		}
		else
			ab->a = ab->a->next;
	}
	i++;
	if (i != check)
		return (0);
	return (1);
}
