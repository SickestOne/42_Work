/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:02:56 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/13 10:27:46 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ctrl	*move_first_20(t_ctrl *ab)
{
	int len;
	int i;

	len = count_nodes_a(ab);
	i = len / 4;
	give_ranks(ab, 1);
	while (count_nodes_b(ab) != i)
		move_number(ab);
	return (ab);
}

int	best_to_move_top(t_ctrl *ab, int i)
{
	int stack_len;
	int target_pos;
	int stack_mid;

	stack_len = count_nodes_a(ab) / 5;
	stack_mid = count_nodes_a(ab) / 2;
	target_pos = 1;
	while (ab->a->next != NULL)
	{
		if (ab->a->rank <= stack_len && target_pos < stack_mid)
		{
			target_pos = i;
		//	printf("pos : %d | rank : %d | data : %d\n", target_pos, ab->a->rank, ab->a->data);
			break ;
		}
		ab->a = ab->a->next;
		i++;
	}
	go_top_a(ab);
//	printf("moves to top = %d\n", target_pos);
	return (target_pos);
}

int	best_to_move_down(t_ctrl *ab, int i)
{
	int stack_len;
	int target_pos;
	int stack_mid;

	stack_len = count_nodes_a(ab) / 5;
	stack_mid = count_nodes_a(ab) / 2;
	target_pos = 1;
	go_down_a(ab);
	while (ab->a->prev != NULL)
	{
		if (ab->a->rank <= stack_len && target_pos < stack_mid)
		{
			target_pos = i;
			//printf("pos : %d | rank : %d | data : %d\n", target_pos, ab->a->rank, ab->a->data);
			break ;
		}
		ab->a = ab->a->prev;
		i++;
	}
	go_top_a(ab);
//	printf("moves to top = %d\n", target_pos);
	return (target_pos);
}

t_ctrl *move_number(t_ctrl *ab)
{
	int move_one;
	int move_two;

	move_one = best_to_move_top(ab, 1);
	move_two = best_to_move_down(ab, 1);
	if (move_two > move_one)
	{
		while (move_one != 0)
		{
			rotate_a(ab, 1);
			move_one--;
		}
		push_b(ab, 1);
		go_top_a(ab);
		return (ab);
	}
	while (move_two != 0)
	{
		rra(ab, 1);
		move_two--;
	}
	push_b(ab, 1);
	go_top_a(ab);
	return (ab);
}
