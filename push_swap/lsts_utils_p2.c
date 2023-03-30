/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts_utils_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:10:58 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/30 18:46:15 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nodes_a(t_ctrl *ab)
{
	int i;

	i = 0;
	while (ab->a->prev != NULL)
	{
		ab->a = ab->a->prev;
		i++;
	}
	i++;
	return (i);
}

int	count_nodes_b(t_ctrl *ab)
{
	int i;

	i = 0;
	while (ab->b->prev != NULL)
	{
		ab->b = ab->b->prev;
		i++;
	}
	i++;
	return (i);
}

t_ctrl	*go_top_a(t_ctrl *ab)
{
	while (ab->a->prev != NULL)
		ab->a = ab->a->prev;
	return (ab);
}

t_ctrl	*go_top_b(t_ctrl *ab)
{
	while (ab->b->prev != NULL)
		ab->b = ab->b->prev;
	return (ab);
}

void	print_list_a(t_ctrl *ab)
{
	while (ab->a->next != NULL)
	{
		printf("%d\n", ab->a->data);
		ab->a = ab->a->next;
	}
	printf("%d\n", ab->a->data);
}
