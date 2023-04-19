/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts_utils_p4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:20:59 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/19 22:53:02 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ranks_b(t_ctrl *ab)
{
	while (ab->b->next != NULL)
	{
		if (ab->b->rank == 0)
			return (0);
		ab->b = ab->b->next;
	}
	return (1);
}

int	find_max(t_ctrl *ab)
{
	int	tmp;
	int	pos;
	int	fin_pos;

	tmp = ab->a->data;
	pos = 1;
	fin_pos = 0;
	while (ab->a->next != NULL)
	{
		if (tmp < ab->a->next->data)
		{
			tmp = ab->a->next->data;
			fin_pos = pos + 1;
		}
		ab->a = ab->a->next;
		pos++;
	}
	if (fin_pos == 0)
		fin_pos++;
	ab = go_top_a(ab);
	return (tmp);
}

int	find_min(t_ctrl *ab)
{
	int	tmp;
	int	pos;
	int	fin_pos;

	tmp = ab->a->data;
	pos = 1;
	fin_pos = 0;
	while (ab->a->next != NULL)
	{
		if (tmp > ab->a->next->data)
		{
			tmp = ab->a->next->data;
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

int	find_min_pos_b(t_ctrl *ab)
{
	int	tmp;
	int	pos;
	int	fin_pos;

	tmp = ab->b->data;
	pos = 1;
	fin_pos = 0;
	while (ab->b->next != NULL)
	{
		if (tmp > ab->b->next->data)
		{
			tmp = ab->b->next->data;
			fin_pos = pos + 1;
		}
		ab->b = ab->b->next;
		pos++;
	}
	if (fin_pos == 0)
		fin_pos++;
	go_top_b(ab);
	return (tmp);
}

int	find_max_b(t_ctrl *ab)
{
	int	tmp;
	int	pos;
	int	fin_pos;

	tmp = ab->b->data;
	pos = 1;
	fin_pos = 0;
	while (ab->b->next != NULL)
	{
		if (tmp < ab->b->next->data)
		{
			tmp = ab->b->next->data;
			fin_pos = pos + 1;
		}
		ab->b = ab->b->next;
		pos++;
	}
	if (fin_pos == 0)
		fin_pos++;
	go_top_b(ab);
	return (tmp);
}
