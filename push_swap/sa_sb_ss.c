/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:47:45 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/28 20:50:13 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ctrl *swap_a(t_ctrl *ab)
{
	t_node *tmp;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
		return (ab);
	ab = go_top(ab);
	tmp = ab->a->next->prev;
	printf("tmp val: %d\n", tmp->data);
	ab->a = ab->a->next;
	ab->a->prev = NULL;
	return (ab);
}
