/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:32:23 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/16 15:56:24 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *node_init(char **argv)
{
	t_node *node;
	static int i = 1;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->data = ft_atoi(argv[i]);
	printf("%d\n", node->data);
	node->next = NULL;
	return (node);
}

