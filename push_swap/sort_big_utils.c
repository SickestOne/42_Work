/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:22:48 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/17 17:20:47 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Demmerde toi pour regler le probleme du dernier tour pour 500
// sans baiser l'algo pour 100.
// Une fois que ok, tente d'opti pour 500, sinon longue vie et nikoumouk.

void fill_b(t_ctrl *ab, int inter_max, int inter_min)
{
	if (ab->a->rank > inter_min && ab->a->rank <= inter_max)
		push_b(ab, 1);
	else
		rotate_a(ab, 1);
}

void fill_b_opti(t_ctrl *ab, int inter_max, int inter_min, int cut_coef)
{
	(void)cut_coef;
	if (count_nodes_b(ab) == (inter_max - inter_min) && ab->a->rank < inter_min
		&& count_nodes_a(ab) > 100)
	{
		while (ab->a->rank < inter_min)
			rotate_a(ab, 1);
	}
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
