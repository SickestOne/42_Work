/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:32:23 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/17 15:01:21 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *node_init(char **argv)
{
	static int i = 1;
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = ft_atoi(argv[i]);
	printf("%d\n", node->data);
	node->next = NULL;
	i++;

	t_node *node_2;
	node_2 = malloc(sizeof(t_node));
	node_2->data = ft_atoi(argv[i]);
	printf("%d\n", node_2->data);
	node_2->next = NULL;
	node->next = node_2;
	return (node);
}

