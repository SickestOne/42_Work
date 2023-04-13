/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:19:57 by pendejoo          #+#    #+#             */
/*   Updated: 2023/04/13 10:07:34 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chose_sort_sa(int argc, char **str)
{
	char **temp;
	t_ctrl *ab;
	int len;

	temp = ft_split((const char *)str[1], ' ');
	len = sa_tab_len(temp);
	ab = NULL;
	if (len <= 5)
	{
		ab = build_stack_a_sa(argc, str, 0);
		sort_small(ab, len);
	}
	else if (len <= 100)
	{
		ab = build_stack_a_sa(argc, str, 0);
		give_ranks(ab, 1);
	}
	return (0);
}

int	chose_sort_ma(int argc, char **str)
{
	int len;
	t_ctrl *ab;

	len = ma_tab_len(str);
	ab = NULL;
	if (len <= 5)
	{
		ab = build_stack_a_ma(argc, str, 1);
		sort_small(ab, len);
	}
	else if (len <= 100)
	{
		ab = build_stack_a_ma(argc, str, 1);
	//	best_to_move_top(ab, 1);
	//	best_to_move_down(ab, 1);
		move_first_20(ab);
	//	move_first_20(ab, 0);
	}
	return (0);
}
