/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:32:23 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/17 17:14:36 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node_a *node_init(int argc, char **argv)
{
	static int i = 1;
	t_node_a *node;

	while (i < argc)
	{
		node = malloc(sizeof(t_node_a));
		if (!node)
			return (NULL);
		node->data = ft_atoi(argv[i]);
		//printf("%d\n", node->data);
		node = node->next;
		i++;
	}
	node = NULL;
	return (node);
}

