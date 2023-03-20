/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:32:23 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/20 15:46:28 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *node_init(char **argv)
{
	static int i = 1;
	t_node *stack_a;

	stack_a = ft_lstnew((int)ft_atoi(argv[i]));
	printf("%d\n", stack_a->data);
	return (stack_a);
}
