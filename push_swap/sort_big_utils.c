/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:22:48 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/19 13:50:54 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Demmerde toi pour regler le probleme du dernier tour pour 500
// sans baiser l'algo pour 100.
// Une fois que ok, tente d'opti pour 500, sinon longue vie et nikoumouk.

void fill_b(t_ctrl *ab, int inter_max, int inter_min)
{
	while (a_has_rank(ab, inter_max, inter_min) != 1)
	{
		if (ab->a->rank >= inter_min && ab->a->rank <= inter_max)
			push_b(ab, 1);
		else
			rotate_a(ab, 1);
	}
}

void fill_b_opti(t_ctrl *ab, int inter_max, int inter_min, int cut_coef)
{
	int total_b;

	total_b = count_nodes_b(ab);
	(void)cut_coef;
	if (count_nodes_b(ab) == (inter_max - inter_min) && ab->a->rank <= inter_min
		&& count_nodes_a(ab) > 100)
	{
		while (ab->a->rank < inter_min)
			rotate_a(ab, 1);
	}
}

void out_of_range(t_ctrl *ab, int cut_coef, int total_len)
{
	(void)cut_coef;
	if (total_len != 100 && total_len != 500)
	{
		while (ab->a->data < ab->a->next->data)
			rra(ab, 1);
		rotate_a(ab, 1);
	}
}

void	in_range_500(t_ctrl *ab)
{
	while (ab->a->data < ab->a->next->data)
		rotate_a(ab, 1);
	rotate_a(ab, 1);
}

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
	{
		printf("not sorted\n");
		return (0);
	}
	printf("Sorted\n");
	return (1);
}
