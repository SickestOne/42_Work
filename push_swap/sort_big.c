/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:02:56 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/12 22:28:52 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*t_ctrl	*move_first_20(t_ctrl *ab, int pos)
{
	int len;
	int i;

	len = count_nodes_a(ab);
	i = len / 4;
	give_ranks(ab, 1);
	while (count_nodes_b(ab) != len)
	{
	}
	return (ab);
}*/

int	best_to_move(t_ctrl *ab)
{
	int stack_len;
	int i;
	int target_pos;

	give_ranks(ab, 1);
	stack_len = count_nodes_a(ab) / 5;
	target_pos = 1;
	i = 1;
	while (ab->a->next != NULL)
	{
		if (ab->a->rank <= stack_len)
		{
			target_pos = i;
			printf("pos : %d | rank : %d | data : %d\n", target_pos, ab->a->rank, ab->a->data);
		}
		ab->a = ab->a->next;
		i++;
	}
	return (target_pos);
}
