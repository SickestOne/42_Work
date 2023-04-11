/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:02:56 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/11 15:56:09 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_find_min(t_ctrl *ab, int j)
{
	int	i;
	int	n;
	int pos;

	i = count_nodes_a(ab) / 5;
	n = count_nodes_a(ab);
	pos = 0;
	while (j != i)
	{
		pos = find_min(ab);
		if (find_min(ab) < n / 2)
			move_nb_a_le_50(ab, pos);
		else if (find_min(ab) > n /2)
			move_nb_a_se_50(ab, pos);
		pos = 0;
		j++;
		n = count_nodes_a(ab);
		go_top_a(ab);
	}
}

t_ctrl	*move_nb_a_le_50(t_ctrl *ab, int pos)
{
	while (pos != 1)
	{
		rotate_a(ab, 1);
		pos--;
	}
	push_b(ab, 1);
	go_top_a(ab);
	return (ab);
}

t_ctrl	*move_nb_a_se_50(t_ctrl *ab, int pos)
{
	pos = count_nodes_a(ab) - pos;
	while (pos != -1)
	{
		rra(ab, 1);
		pos--;
	}
	push_b(ab, 1);
	go_top_a(ab);
	return (ab);
}
