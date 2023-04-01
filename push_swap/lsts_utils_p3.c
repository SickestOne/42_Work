/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts_utils_p3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:45:48 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/01 16:58:50 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	print_list_b(t_ctrl *ab)
{
	if (ab->b == NULL)
	{
		printf("b : is empty\n");
		return ;
	}
	while (ab->b->next != NULL)
	{
		printf("b : %d\n", ab->b->data);
		ab->b = ab->b->next;
	}
	printf("b : %d\n", ab->b->data);
	go_top_b(ab);
}
