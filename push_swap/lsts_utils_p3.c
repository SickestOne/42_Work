/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts_utils_p3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:45:48 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/30 18:47:25 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	print_list_b(t_ctrl *ab)
{
	while (ab->b->next != NULL)
	{
		printf("%d\n", ab->b->data);
		ab->a = ab->b->next;
	}
	printf("%d\n", ab->b->data);
}
