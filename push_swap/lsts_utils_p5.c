/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts_utils_p5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:29:53 by pendejoo          #+#    #+#             */
/*   Updated: 2023/04/21 10:59:37 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos_b(t_ctrl *ab)
{
	int	tmp;
	int	pos;
	int	fin_pos;

	tmp = ab->b->rank;
	pos = 1;
	fin_pos = 0;
	while (ab->b->next != NULL)
	{
		if (tmp < ab->b->next->rank)
		{
			tmp = ab->b->next->rank;
			fin_pos = pos + 1;
		}
		ab->b = ab->b->next;
		pos++;
	}
	if (fin_pos == 0)
		fin_pos++;
	go_top_b(ab);
	return (fin_pos);
}

int	find_min_pos_b(t_ctrl *ab)
{
	int	tmp;
	int	pos;
	int	fin_pos;

	tmp = ab->b->rank;
	pos = 1;
	fin_pos = 0;
	while (ab->b->next != NULL)
	{
		if (tmp > ab->b->next->rank)
		{
			tmp = ab->b->next->rank;
			fin_pos = pos + 1;
		}
		ab->b = ab->b->next;
		pos++;
	}
	if (fin_pos == 0)
		fin_pos++;
	go_top_b(ab);
	return (fin_pos);
}

int	find_min_pos_a(t_ctrl *ab)
{
	int	tmp;
	int	pos;
	int	fin_pos;

	tmp = ab->a->rank;
	pos = 1;
	fin_pos = 0;
	while (ab->a->next != NULL)
	{
		if (tmp > ab->a->next->rank)
		{
			tmp = ab->a->next->rank;
			fin_pos = pos + 1;
		}
		ab->a = ab->a->next;
		pos++;
	}
	if (fin_pos == 0)
		fin_pos++;
	go_top_a(ab);
	return (fin_pos);
}

int	find_max_pos_a(t_ctrl *ab)
{
	int	tmp;
	int	pos;
	int	fin_pos;

	tmp = ab->a->rank;
	pos = 1;
	fin_pos = 0;
	while (ab->a->next != NULL)
	{
		if (tmp < ab->a->next->rank)
		{
			tmp = ab->a->next->rank;
			fin_pos = pos + 1;
		}
		ab->a = ab->a->next;
		pos++;
	}
	if (fin_pos == 0)
		fin_pos++;
	go_top_a(ab);
	return (fin_pos);
}
