/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:22:48 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/20 22:16:49 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// modify find_xxx_data_b for rank search
void	fill_b(t_ctrl *ab, int inter_max, int inter_min)
{
	//int	total_len;

	while (a_has_rank(ab, inter_max, inter_min) != 1)
	{
		// if (find_max_rank >= i_min && find_max_rank <= i_max)
		//		if (find_max_pos > tot_len / 2 + 1)
		//			while (find_max_pos < total_len)
		//				rra;
		//			pb;
		//		else if (find_max_pos < total_len / 2 + 1)
		//			while(find_max_pos > 1)
		//				ra;
		//			pb;
		//		else if (ab->a->rank >= i_min && ab->a->rank <= i_max)
		//			pb;
		//		else
		//			rotate_a;
		if (ab->a->rank >= inter_min && ab->a->rank <= inter_max)
			push_b(ab, 1);
		else
			rotate_a(ab, 1);
	}
}

void	out_of_range(t_ctrl *ab, int cut_coef, int total_len)
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
