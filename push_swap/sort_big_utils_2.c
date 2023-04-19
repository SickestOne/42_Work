/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:39:34 by pendejoo          #+#    #+#             */
/*   Updated: 2023/04/19 23:11:57 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	combine_first_if(t_ctrl *ab, int total_len)
{
	go_down_a(ab);
	while (ab->a->rank < total_len)
		rra(ab, 1);
	go_top_a(ab);
}

/*int	a_is_sorted(t_ctrl *ab)
{
	int	i;
	int	check;

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
}*/
