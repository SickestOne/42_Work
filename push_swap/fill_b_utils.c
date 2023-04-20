/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:09:43 by pendejoo          #+#    #+#             */
/*   Updated: 2023/04/20 20:37:09 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_b_case_1(t_ctrl *ab, int total_len)
{
	(void)total_len;
	while (find_max_pos_b(ab) != 1)
		rotate_b(ab, 1);
	push_a(ab, 1);
}
