/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:30:50 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/21 13:18:23 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_a_max_1(t_ctrl *ab)
{
	while (find_max_pos_b(ab) != 1)
		rotate_b(ab, 1);
	push_a(ab, 1);
}

void	fill_a_max_2(t_ctrl *ab)
{
	while (find_max_pos_b(ab) != 1)
		rrb(ab, 1);
	push_a(ab, 1);
}

void	fill_a_min_1(t_ctrl *ab)
{
	while (find_min_pos_b(ab) != 1)
		rotate_b(ab, 1);
	push_a(ab, 1);
	rotate_a(ab, 1);
}

void	fill_a_min_2(t_ctrl *ab)
{
	while (find_min_pos_b(ab) != 1)
		rrb(ab, 1);
	push_a(ab, 1);
	rotate_a(ab, 1);
}
